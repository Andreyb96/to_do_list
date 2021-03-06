#include "ToDoList.h"
#include "easylogging++.h"
#include "Utils.h"

#include <fstream>

ToDoList::ToDoList()
{}

void ToDoList::AddTask(const std::string& dateStr, const std::string& task)
{
	LOG(TRACE) << "Add task: " << task << " for date: " << dateStr;
	auto date = Utils::BuildDate(dateStr);
	AddTask(date, { task });
}

void ToDoList::AddTaskForToday(const std::string& task)
{
	LOG(TRACE) << "Add task: " << task << " for today";
	auto date = Utils::GetTodaysDate();
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
	LOG(TRACE) << "Make backup in process...";
	std::ofstream backupFile(filename);
	if (backupFile.is_open())
	{
		for (const auto& tasksForDate : _tasks)
		{
			for (const auto& task : tasksForDate.second)
			{
				backupFile << Utils::BuildDateStr(tasksForDate.first) << "\t" << task.name << "\n";
			}
		}

		backupFile.close();
	}
	LOG(TRACE) << "Backup successfully made...";
}

void ToDoList::LoadBackup(const std::string& filename)
{
	LOG(TRACE) << "Loading backup...";
	std::ifstream backupFile(filename);
	std::string line;
	if (backupFile.is_open())
	{
		while (std::getline(backupFile, line))
		{
			auto tabIt = line.find('\t');
			auto date = Utils::BuildDate(line.substr(0, tabIt));
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
	LOG(TRACE) << "Backup successfully loaded...";
}

size_t ToDoList::GetTasksAmountForDate(const std::string& dateStr)
{
	auto date = Utils::BuildDate(dateStr);
	const auto& it = _tasks.find(date);
	return it != _tasks.end() ? it->second.size() : 0;
}

std::vector<Task> ToDoList::GetTasksForDate(const std::string& dateStr)
{
	auto date = Utils::BuildDate(dateStr);
	const auto& it = _tasks.find(date);
	return it != _tasks.end() ? it->second : std::vector<Task>();
}

size_t ToDoList::GetDatesWithTasksAmount()
{
	return _tasks.size();
}

std::vector<Date> ToDoList::GetDatesWithTasks()
{
	std::vector<Date> result;
	for (const auto& elem : _tasks)
	{
		result.push_back(elem.first);
	}
	return result;
}

void ToDoList::RemoveTask(const std::string& dateStr, const std::string& task)
{
	auto& taskPairIt = _tasks.find(Utils::BuildDate(dateStr));

	if (taskPairIt == _tasks.end())
	{
		LOG(WARNING) << "No tasks for date: " << dateStr;
		return;
	}

	auto taskIt = std::find(taskPairIt->second.begin(), taskPairIt->second.end(), Task({ task }));

	if (taskIt == taskPairIt->second.end())
	{
		LOG(WARNING) << "Task: " << task << " for date: " << dateStr << " doesn't exist";
		return;
	}

	taskPairIt->second.erase(std::remove(taskPairIt->second.begin(), taskPairIt->second.end(), Task({ task })));
}

void ToDoList::RemoveAllTasksForDate(const std::string& dateStr)
{
	_tasks.erase(Utils::BuildDate(dateStr));
}

void ToDoList::RemoveAllTasksForToday()
{
	auto date = Utils::GetTodaysDate();
	auto dateStr = Utils::BuildDateStr(date);
	RemoveAllTasksForDate(dateStr);
}

void ToDoList::RemoveAllTasks()
{
	_tasks.clear();
}