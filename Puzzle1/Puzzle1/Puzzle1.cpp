// Puzzle1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

struct LogEntry
{
	std::tm dateTime;
	int id;
	bool asleep;
};

LogEntry ParseLine(std::string line, int *pCurGuard)
{
	LogEntry logEntry = {};
	std::istringstream dateString(line.substr(1, 16));
	dateString >> std::get_time(&logEntry.dateTime, "%Y-%m-%d %H:%M");
	if (line.substr(19, 5) == "Guard")
	{
		int guardId = std::stoi(line.substr(26));
		*pCurGuard = guardId;
		logEntry.asleep = false;
	}
	else if (line.substr(19) == "falls asleep")
	{
		logEntry.asleep = true;
	}
	else if (line.substr(19) == "wakes up")
	{
		logEntry.asleep = false;
	}
	else
	{
		assert(!"What the.... ?");
	}
	logEntry.id = *pCurGuard;
	return logEntry;
}



int main()
{
    std::vector<std::string> lines;
	std::map<std::time_t, LogEntry> logEntries;
	std::unordered_map<int, unsigned> guardSleepingMinutesMap;
    std::ifstream myFile;
    myFile.open("Guards.txt");
	int curGuard = -1;


    if (myFile.is_open())
    {
        for (;;)
        {
            std::string line;
            std::getline(myFile, line);
			LogEntry entry = ParseLine(line, &curGuard);
			std::time_t time = std::mktime(&entry.dateTime);
			logEntries.emplace(time, entry);

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

	for (auto it : logEntries)
	{
		int guardId = it.second.id;
		//guardSleepingMinutesMap.
	}
    
    return 0;
}

