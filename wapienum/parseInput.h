#pragma once
#include <string>
#include <iostream>
#include <sstream>
#include "functions/get_username.h"
#include "functions/net_userenum.h"
#include "functions/net_wkstagetinfo.h"
#include "functions/net_shareenum.h"

std::string GetNthWord(std::string s, std::size_t n)
{
    std::istringstream iss(s);
    while (n-- > 0 && (iss >> s));
    return s;
}

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
    
    if (s == "net_wkstagetinfo")
    {
        net_wkstagetinfo();
    }

    if (s == "net_shareenum")
    {
        net_shareenum();
    }

    if (s == "exit")
    {
        exit(0);
    }

    if (s == "help")
    {
        std::cout << "help: get_username,net_userenum,net_wkstagetinfo,net_shareenum,exit" << "\n";
    }


    return 0;
}
