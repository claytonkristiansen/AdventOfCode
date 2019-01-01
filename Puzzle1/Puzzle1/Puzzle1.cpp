// Puzzle1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#define TWO_COUNT 0x01
#define THREE_COUNT 0x02

int main()
{
    int twoCount = 0;
    int threeCount = 0;
    std::ifstream myFile;
    std::string line;
    myFile.open("BoxIDs.txt");
    if (myFile.is_open())
    {
        for (;;)
        {
            int alphabet[26] = {0};
            std::getline(myFile, line);
            for (auto ch : line)
            {
                int index = ch - 'a';
                alphabet[index]++;
            }
            
            int status = 0;

            for (auto integerCount : alphabet)
            {

                if (integerCount == 2 && 0 == (status & TWO_COUNT))
                {
                    twoCount++;
                    status |= TWO_COUNT;
                }
                else if (integerCount == 3 && 0 == (status & THREE_COUNT))
                {
                    threeCount++;
                    status |= THREE_COUNT;
                }
            }
            
            if (myFile.eof())
            {
                break;
                /*myFile.seekg(myFile.beg);*/
            }
        }
    }
    else
    {
        std::cout << "file failed to open\n";
        return 0;
    }
    myFile.close();
    return twoCount * threeCount;
}

