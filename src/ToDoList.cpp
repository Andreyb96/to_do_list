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
		return Date();
	}
} //anonymos

ToDoList::ToDoList()
{}

void ToDoList::AddTask(const std::string& dateStr, const std::string& task)
{
	auto date = BuildDate(dateStr);
	//auto& it = _tasks.find(Date());
	//if (it == _tasks.end())
	//{
	//	_tasks.insert({ date, {task} });
	//	return;
	//}
	//it->second.push_back(task);
}

void ToDoList::AddTaskForToday(const std::string& task)
{
	auto date = GetTodaysDate();
	auto& it = _tasks.find(date);
	if (it == _tasks.end())
	{
		_tasks.insert({ date, {{task}} });
		return;
	}
	it->second.push_back({ task });
}