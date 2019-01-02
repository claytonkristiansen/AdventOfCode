// Puzzle1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

int SimilarCompare(std::string string1, std::string string2)
{
    int mismatchIndex = -1;
    for (int i = 0; i < string1.length(); ++i)
    {
        if (string1[i] != string2[i])
        {
            if (mismatchIndex >= 0)
            {
                return -1; //If there is more than one mismatch they are not similar
            }
            mismatchIndex = i;
        }
    }
    return mismatchIndex; //Must have only one mismatch
}


int main()
{
    std::vector<std::string> lines;
    std::ifstream myFile;
    myFile.open("BoxIDs.txt");

    if (myFile.is_open())
    {
        for (;;)
        {
            std::string line;
            std::getline(myFile, line);
            lines.push_back(line);
            
            if (myFile.eof())
            {
                break;
            }
        }
        
    }
    else
    {
        std::cout << "file failed to open\n";
        return 0;
    }
    myFile.close();
    if (lines.size() >= 2)
    {
        for (auto it = lines.begin(); it != lines.end() - 1; ++it)
        {
            for (auto it2 = it + 1; it2 != lines.end(); ++it2)
            {
                int mismatchIndex = SimilarCompare(*it, *it2);
                if (mismatchIndex >= 0)
                {
                    std::string s = it->substr(0, mismatchIndex) + it->substr(mismatchIndex + 1);
                    std::cout << s;
                }
            }
        }
    }

    return 0;
}

