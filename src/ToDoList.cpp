#include "ToDoList.h"

#include <ctime>
#include <iostream>

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