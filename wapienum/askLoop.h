#pragma once

#include "parseInput.h"
#include <iostream>

int askLoop()
{
    std::string line;

    std::cout << "Type 'help' for a list of commands you can run.\n";

    std::cout << "> ";
    while (std::getline(std::cin, line))
    {
        #if defined _DEBUG
                    std::cout << "answer: " << s << "\n";
        #endif
        parseInput(line);
        std::cout << "> ";
    }

    return 0;
}