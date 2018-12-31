// Puzzle1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>

int main()
{
    int frequency = 0;
    std::ifstream myFile;
    std::string line;
    myFile.open("FrequencyChanges.txt");
    if (myFile.is_open())
    {
        for (;!myFile.eof();)
        {
            std::getline(myFile, line);
            frequency += std::stoi(line);
        }
    }
    else
    {
        std::cout << "file failed to open\n";
        return 0;
    }
    myFile.close();
    return frequency;
}

