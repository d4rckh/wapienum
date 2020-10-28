#pragma once
#include <string>
#include <iostream>
#include "functions/get_username.h"
#include "functions/net_userenum.h"

int parseInput(std::string s) {

    #if defined _DEBUG
        std::cout << "Parsing: " << s << "\n";
    #endif

    if (s == "get_username") 
    {
        std::string username = get_username();
        std::cout << "Current User is: " << username << "\n";
    }

    if (s == "net_userenum")
    {
        net_userenum();
    }

    if (s == "help")
    {
        std::cout << "help: get_username,net_userenum" << "\n";
    }

    return 0;
}
