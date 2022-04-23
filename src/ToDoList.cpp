#include "ToDoList.h"

namespace
{
	std::string GetTodaysDate()
	{
		return "";
	}
} //anonymos

ToDoList::ToDoList()
{}

void ToDoList::AddTask(const std::string& date, const std::string& task)
{
	auto& it = _tasks.find(date);
	if (it == _tasks.end())
	{
		_tasks.insert({ date, {task} });
		return;
	}
	it->second.push_back(task);
}

void ToDoList::AddTaskForToday(const std::string& task)
{
	auto date = GetTodaysDate();
	auto& it = _tasks.find(date);
	if (it == _tasks.end())
	{
		_tasks.insert({ date, {task} });
		return;
	}
	it->second.push_back(task);
}