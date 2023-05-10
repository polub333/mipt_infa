#ifndef UTIL_H
#define UTIL_H

#include <iostream>

static void PrintToDo(const char* file, int line, const char* msg){
    std::cerr << "[ TODO ]" << msg << "@" << file << ":" << line << std::endl;
}

static void PrintError(const char* file, int line, const char* msg){
    std::cerr << "[ ERROR! ]" << msg << "@" << file << ":" << line << std::endl;
}

#define TODO(msg) PrintToDo(__FILE__, __LINE__, #msg)
#define ASSERT(stmt) do{\
                            if(!stmt){\
                                PrintError(__FILE__, __LINE__, #stmt);\
                            }\
                     }while(0)

#endif // UTIL_H
