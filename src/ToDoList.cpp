#include "ToDoList.h"

#include <ctime>
#include <fstream>

namespace
{
	Date GetTodaysDate()
	{
		auto t = std::time(0);
		auto currentTime = std::localtime(&t);
		return { currentTime->tm_mday,  currentTime->tm_mon + 1, currentTime->tm_year + 1900 };
	}

	Date BuildDate(const std::string& date)
	{
		auto firstIt = date.find('-');
		auto lastIt = date.find_last_of('-');
		return { std::stoi(date.substr(0, firstIt))
		, std::stoi(date.substr(firstIt + 1, lastIt))
		, std::stoi(date.substr(lastIt + 1)) };
	}

	std::string BuildDateStr(const Date& date)
	{
		return std::to_string(date.day) +
			'-' + std::to_string(date.month) +
			'-' + std::to_string(date.year);
	}
} //anonymos

ToDoList::ToDoList()
{}

void ToDoList::AddTask(const std::string& dateStr, const std::string& task)
{
	auto date = BuildDate(dateStr);
	AddTask(date, { task });
}

void ToDoList::AddTaskForToday(const std::string& task)
{
	auto date = GetTodaysDate();
	AddTask(date, { task });
}

void ToDoList::AddTask(const Date& date, const Task& task)
{
	auto& it = _tasks.find(date);
	if (it == _tasks.end())
	{
		_tasks.insert({ date, {{task}} });
		return;
	}
	it->second.push_back({ task });
}

void ToDoList::MakeBackup(const std::string& filename)
{
	std::ofstream backupFile(filename);
	if (backupFile.is_open())
	{
		for (const auto& tasksForDate : _tasks)
		{
			for (const auto& task : tasksForDate.second)
			{
				backupFile << BuildDateStr(tasksForDate.first) << "\t" << task.name << "\n";
			}
		}

		backupFile.close();
	}
}

void ToDoList::LoadBackup(const std::string& filename)
{
	std::ifstream backupFile(filename);
	std::string line;
	if (backupFile.is_open())
	{
		while (std::getline(backupFile, line))
		{
			auto tabIt = line.find('\t');
			auto date = BuildDate(line.substr(0, tabIt));
			auto dateIt = _tasks.find(date);

			if (dateIt == _tasks.end())
			{
				_tasks.insert({ date, { {line.substr(tabIt + 1)} } });
			}
			else
			{
				dateIt->second.push_back({ line.substr(tabIt + 1) });
			}
		}
		backupFile.close();
	}
}