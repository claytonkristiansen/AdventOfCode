// Puzzle1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>

using namespace std;

int main()
{
    ifstream myFile;
    myFile.open("FrequencyChanges.txt");
    if (myFile.is_open())
    {
        string line;
        while (getline(myFile, line))
        {
            cout << line << "\n";
        }
    }
    else
    {
        cout << "file failed to open\n";
        return 0;
    }
    myFile.close();
    return 0;
}

