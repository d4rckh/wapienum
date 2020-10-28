#pragma once
#include <string>
#include <iostream>
#include "functions/get_username.h"

int parseInput(std::string s) {

#if defined _DEBUG
    std::cout << "Parsing: " << s << "\n";
#endif

    if (s == "get_username") 
    {
        std::string username = get_username();
        std::cout << "Current User is: " << username << "\n";
    }

    return 0;
}
