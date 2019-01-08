#include "Command.h"
#include "OpenServerCommand.h"
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <thread>
#include <netdb.h>
#include <unistd.h>
#include <netinet/in.h>
#include "GlobalTables.h"
#include <string.h>
#include "ShuntingYard.h"
#include <sys/socket.h>
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreserved-user-defined-literal"
using namespace std;
static int socketServer;


int OpenServerCommand::execute(vector<string> cmdTemp, int index){
    ShuntingYard sY = ShuntingYard();
    string port, time;
    int pos = 0;
   int endLine = enterKey(cmdTemp, index);
   string s = vectorToString(cmdTemp,index, index + endLine);
   if(s.find(",", pos) == string::npos) {
       string port = to_string(sY.calculate(cmdTemp.at(index + 1)));
       string time = to_string(sY.calculate(cmdTemp.at(index + 2)));

       openSocket(stoi(port), stoi(time));
   }
   else {
       string port = to_string(sY.calculate(s.substr(0,pos)));
       string time = to_string(sY.calculate(s.substr(pos + 1, s.length() - 1)));

       openSocket(stoi(port), stoi(time));
   }
   return 3;
}

void OpenServerCommand::openSocket(int port, int time) {
   int sockfd, newsockfd, portno, clilen;
   struct sockaddr_in serv_addr, cli_addr;

   /* First call to socket() function */
   sockfd = socket(AF_INET, SOCK_STREAM, 0);

   if (sockfd < 0) {
      perror("ERROR opening socket");
      exit(1);
   }

   /* Initialize socket structure */
   bzero((char *) &serv_addr, sizeof(serv_addr));
   portno = port;

   serv_addr.sin_family = AF_INET;
   serv_addr.sin_addr.s_addr = INADDR_ANY;
   serv_addr.sin_port = htons(portno);

   /* Now bind the host address using bind() call.*/
   if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
      perror("ERROR on binding");
      exit(1);
   }

   socketServer = sockfd;
   /* Now start listening for the clients, here process will
      * go in sleep mode and will wait for the incoming connection
   */

   listen(sockfd,25);
   clilen = sizeof(cli_addr);
/* Accept actual connection from the client */
   newsockfd = accept(sockfd, (struct sockaddr *)&cli_addr, (socklen_t*)&clilen);
   if (newsockfd < 0) {
      perror("ERROR on accept");
      exit(1);
   }

   socketServer = newsockfd;

    pthread_t t2;
    pthread_create(&t2,nullptr,&OpenServerCommand::runServer,this);
}

void *OpenServerCommand::runServer(void *args) {
    char buffer[1024];
    int n;
    vector<double> vecTemp;
    bzero(buffer,1025);
    while(!endSignal) {
        bzero(buffer,1025);
        n = (int)read(socketServer, buffer, 1025);
        if (n < 0) {
            perror("ERROR reading from socket");
            pthread_exit(NULL);
        }
        vecTemp = buffToDouble(buffer);
        updateTable(vecTemp);
    }
    pthread_exit(&args);
}

vector<double> OpenServerCommand::buffToDouble(string buffer) {
    string temp;
    vector<double> vecTemp;

    int base = 0, j = 0;
    for(int i = 0; i < (int)(buffer.length()) && j < (int)(symbolServer.size()); i++) {
        if(buffer[i] == ',') {
            j++;
            temp = buffer.substr(base,i - base);
            base += i - base + 1;
            try {
                vecTemp.push_back(stod(temp));
            }
            catch(std::invalid_argument) {
                printf("Not of double type\n");
                vecTemp.push_back(0);
            }
        }
    }
    return vecTemp;
}

void *OpenServerCommand::updateTable(vector<double> vecTemp) {
    string location;
    while(!runClient) {
        sleep(10);
    }
    try {
        for (int i = 0; i < (int)(vecTemp.size()); i++) {
            location = tableOrder.at(i);
            symbolServer.at(location) = vecTemp.at(i);
            cout << location + " " + to_string((int)symbolServer.at(location)) << endl;
        }
    }catch(std::out_of_range) {
        printf("Index exceding vector's size\n");
    }
    cout << endl;
    usleep(100);
}

int OpenServerCommand::enterKey(vector<string> vec, int index){
    int i = 0;
    while(vec.at(index + i) != "\n") {
        i++;
    }
    return i;
}

string OpenServerCommand::vectorToString(vector<string> vector, int index, int end) {
    string ret = vector.at(index) + " ";
    int i = 1;
    while(index + i < end){
        if(ret.length() > 1)
            ret += vector.at(index + i) + " ";
        else {
            break;
        }
        i++;
    }
    return ret;
}

OpenServerCommand::~OpenServerCommand() = default;

#pragma clang diagnostic pop