#pragma once

#include "parseInput.h"
#include <iostream>

int askLoop()
{
    std::string s;

    std::cout << "> "; std::cin >> s;
    std::cout << "answer: " << s << "\n";

    parseInput(s);
    askLoop();

    return 0;
}