// Puzzle1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

struct Rectangle
{
    int id = 0;
    int x = 0;
    int y = 0;
    int width = 0;
    int height = 0;

    Rectangle(int ID, int X, int Y, int Width, int Height)
        :id(ID), x(X), y(Y), width(Width), height(Height)
    {

    }

    Rectangle()
    {

    }
};

Rectangle ParseLine(std::string line)
{
    Rectangle result = {};

    size_t itFirst = line.find_first_of('#');
    itFirst++;
    size_t itLast = line.find_first_of('@', itFirst);
    result.id = std::stoi(line.substr(itFirst, itLast - itFirst));

    itFirst = itLast;
    itFirst++;
    itLast = line.find_first_of(',', itFirst);
    result.x = std::stoi(line.substr(itFirst, itLast - itFirst));

    itFirst = itLast;
    itFirst++;
    itLast = line.find_first_of(':', itFirst);
    result.y = std::stoi(line.substr(itFirst, itLast - itFirst));

    itFirst = itLast;
    itFirst++;
    itLast = line.find_first_of('x', itFirst);
    result.width = std::stoi(line.substr(itFirst, itLast - itFirst));

    itFirst = itLast;
    itFirst++;
    itLast = line.find_first_of('\n', itFirst);
    result.height = std::stoi(line.substr(itFirst, itLast - itFirst));

    return result;
}

short pixels[1000][1000] = {0};

int main()
{
    std::vector<std::string> lines;
    std::vector<Rectangle> rectangles;
    std::ifstream myFile;
    myFile.open("FabricClaims.txt");


    if (myFile.is_open())
    {
        for (;;)
        {
            std::string line;
            std::getline(myFile, line);
            Rectangle rect = ParseLine(line);
            rectangles.push_back(rect);

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

    for (auto &rect : rectangles) //This is rasterization
    {
        for (int y = rect.y; y < rect.height + rect.y; ++y)
        {
            for (int x = rect.x; x < rect.width + rect.x; ++x)
            {
                ++pixels[x][y];
            }
        }
    }

    for (auto &rect : rectangles) //This is rasterization
    {
        bool isBad = false;
        for (int y = rect.y; y < rect.height + rect.y; ++y)
        {
            for (int x = rect.x; x < rect.width + rect.x; ++x)
            {
                if (pixels[x][y] > 1)
                {
                    isBad = true;
                    break;
                }
            }
            if (isBad)
            {
                break;
            }
        }
        if (!isBad)
        {
            return rect.id;
        }
    }

    int count = 0;

    for (int y = 0; y < 1000; ++y)
    {
        for (int x = 0; x < 1000; ++x)
        {
            if (pixels[x][y] > 1)
            {
                ++count; // Finds number of pixels that overlap
            }
        }
    }
    
    return count;
}

