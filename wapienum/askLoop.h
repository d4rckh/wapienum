#pragma once

#include "parseInput.h"
#include <iostream>

int askLoop()
{
    std::string s;

    std::cout << "> "; std::cin >> s;
    
    #if defined _DEBUG
        std::cout << "answer: " << s << "\n";
    #endif

    parseInput(s);
    askLoop();

    return 0;
}