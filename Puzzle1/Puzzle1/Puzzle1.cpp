// Puzzle1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


int main()
{
    std::unordered_set<int> frequencies;
    int frequency = 0;
    std::ifstream myFile;
    std::string line;
    myFile.open("FrequencyChanges.txt");
    if (myFile.is_open())
    {
        for (;;)
        {
            std::getline(myFile, line);
            frequency += std::stoi(line);
            if (frequencies.find(frequency) != frequencies.end())
            {
                break;
            }
            else
            {
                frequencies.insert(frequency);
            }
            if (myFile.eof())
            {
                myFile.seekg(myFile.beg);
            }
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

