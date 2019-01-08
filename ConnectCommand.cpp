#include "Command.h"
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include "ShuntingYard.h"
#include <netdb.h>
#include <unistd.h>
#include <netinet/in.h>
#include "GlobalTables.h"
#include <string.h>
#include "ConnectCommand.h"
#include "OpenServerCommand.h"
#include "GlobalTables.h"
#include <sys/socket.h>
using namespace std;

static int socketClient;
/**
 * function name: execute
 * operation: execute data
 * input: vec of strs and index
 * @return int val
 */
int ConnectCommand::execute(vector<string> cmdTemp, int index){
    ShuntingYard* sY = new ShuntingYard();
    int endLine = enterKey(cmdTemp, index);
   string ip = cmdTemp.at(index + 1);
   int porti =  sY->calculate(cmdTemp.at(index + 2));
   connectSocket(porti, ip);
   delete sY;
   return endLine;
}
/**
 * function name: connectSocket
 * operation: connect the socket
 * input: int and str
 * @return void
 */
void ConnectCommand::connectSocket(int port, string ip) {
   int sockfd, portno;
   struct sockaddr_in serv_addr;
   struct hostent *server;

   portno = port;

   /* Create a socket point */
   sockfd = socket(AF_INET, SOCK_STREAM, 0);
   if (sockfd < 0) {
      perror("ERROR opening socket");
      exit(1);
   }
   server = gethostbyname(ip.c_str());

   if (server == NULL) {
      fprintf(stderr,"ERROR, no such host\n");
      exit(0);
   }

   bzero((char *) &serv_addr, sizeof(serv_addr));
   serv_addr.sin_family = AF_INET;
   bcopy(server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
   serv_addr.sin_port = htons(portno);
   /* Now connect to the server */
   if (connect(sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0) {
       perror("ERROR connecting");
       exit(1);
   }

   socketClient = sockfd;
   newOrder = "";
   pthread_t t2;
   pthread_create(&t2, NULL, &ConnectCommand::updateVal, this);
}
/**
 * function name: updateVal
 * operation: update the value
 * input: args*
 * @return void*
 */
void *ConnectCommand::updateVal(void *args) {
    pthread_mutex_t connect;
    connectLock = connect;
    char buffer[256];
    int n;
    runClient = true;
    pthread_mutex_lock(&connect);
    while (!endSignal) {
        /* Send message to the server */

        if (newOrder.length() > 0) {
            n = send(socketClient, newOrder.c_str(), strlen(newOrder.c_str()), 0);

            if (n < 0) {
                perror("ERROR writing to socket");
                pthread_exit(NULL);
            }

            /* Now read server response */
            bzero(buffer, 256);
            n = read(socketClient, buffer, 255);

            printf("\n\tresponse: %s\n\n",buffer);

            if (n < 0) {

                perror("ERROR reading from socket");
                pthread_exit(NULL);
            }
            newOrder = "";
        }
    }
    pthread_mutex_unlock(&connect);
    pthread_exit(&args);
}
/**
 * function name: enterKey
 * operation: enter a key
 * input: vector of strs and index
 * @return int
 */
int ConnectCommand::enterKey(vector<string> vector, int index) {
    int i = 0;
    while(vector.at(index + i) != "\n") {
        i++;
    }
    return i;
}
/**
 * function name: vectorToString
 * operation:convert vec to str
 * input: vector of strs and index
 * @return string
 */
string ConnectCommand::vectorToString(vector<string> vector, int index, int end) {
    string ret = vector.at(index);
    int i = 1;
    while(i < end){
        ret += vector.at(index + i);
    }
    return ret;
}
//constructor
ConnectCommand::ConnectCommand() {

}

ConnectCommand::~ConnectCommand() = default;

