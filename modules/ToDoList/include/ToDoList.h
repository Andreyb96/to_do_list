#ifndef TO_DO_LIST_H
#define TO_DO_LIST_H

#include <map>
#include <string>
#include <vector>

#include "Date.h"

struct Task
{
	std::string name;
};

class ToDoList
{
public:
	ToDoList();

	void AddTask(const std::string& dateStr, const std::string& task);
	void AddTaskForToday(const std::string& task);

	size_t GetTasksAmountForDate(const std::string& dateStr);
	std::vector<Task> GetTasksForDate(const std::string& dateStr);

	void MakeBackup(const std::string& filename);
	void LoadBackup(const std::string& filename);
private:
	void AddTask(const Date& date, const Task& task);
private:
	std::map<Date, std::vector<Task>> _tasks;
};

#endif // TO_DO_LIST_H