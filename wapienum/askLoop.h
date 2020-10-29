#pragma once

#include "parseInput.h"
#include <iostream>

int askLoop()
{
    std::string s;

    while (true)
    {
        std::cout << "> "; std::cin >> s;
        #if defined _DEBUG
                std::cout << "answer: " << s << "\n";
        #endif
        parseInput(s);
    }

    return 0;
}