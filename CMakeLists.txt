cmake_minimum_required(VERSION 3.12)
project(untitled1)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_CXX_FLAGS -pthread)

add_executable(untitled1 main.cpp Parser.cpp Parser.h Lexer.cpp Lexer.h Command.h ConnectCommand.cpp ShuntingYard.cpp ShuntingYard.h Plus.cpp Plus.h Minus.cpp Minus.h Mult.h Mult.cpp Neg.cpp Neg.h Div.cpp Div.h OpenServerCommand.cpp OpenServerCommand.h ConnectCommand.h BinaryExpression.h BinaryExpression.cpp UnaryExpression.h Num.cpp Num.h Expression.h VarCommand.cpp VarCommand.h PrintCommand.cpp PrintCommand.h LoopCommand.cpp LoopCommand.h GlobalTables.cpp GlobalTables.h ChangeCommand.cpp ChangeCommand.h ConditionParser.cpp ConditionParser.h CommandExpression.cpp CommandExpression.h UnaryExpression.cpp SleepCommand.cpp SleepCommand.h IfCommand.cpp IfCommand.h IfCommand.h EnterCommand.cpp EnterCommand.h Var.cpp Var.h)