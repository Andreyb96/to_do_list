#ifndef TO_DO_LIST_H
#define TO_DO_LIST_H

#include <map>
#include <string>
#include <vector>

class ToDoList
{
public:
	ToDoList();
	void AddTask(const std::string& date, const std::string& task);
	void AddTaskForToday(const std::string& task);

private:
	std::map<std::string, std::vector<std::string>> _tasks;
};

#endif // TO_DO_LIST_H