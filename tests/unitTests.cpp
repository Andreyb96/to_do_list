#include "gtest/gtest.h"
#include "ToDoList.h"
#include "easylogging++.h"
#include "Utils.h"

#include <filesystem>

INITIALIZE_EASYLOGGINGPP

constexpr auto TASK_NAME = "task name";
constexpr auto DATE_NAME = "22-04-2022";
constexpr auto BACKUP_FILENAME = "test_data/backup_example.txt";
constexpr auto CREATE_BACKUP_FILENAME = "my_backup.txt";

TEST(ToDoListTests, AddTaskForTodayNormal)
{
	ToDoList list;
	list.AddTaskForToday(TASK_NAME);
	auto date = Utils::BuildDateStr(Utils::GetTodaysDate());
	ASSERT_TRUE(list.GetTasksAmountForDate(date) == 1);
	ASSERT_TRUE(list.GetTasksForDate(date) == std::vector<Task>({ Task({TASK_NAME}) }));
}

TEST(ToDoListTests, AddTaskNormal)
{
	ToDoList list;
	list.AddTask(DATE_NAME, TASK_NAME);
	ASSERT_TRUE(list.GetTasksAmountForDate(DATE_NAME) == 1);
	ASSERT_TRUE(list.GetTasksForDate(DATE_NAME) == std::vector<Task>({ {TASK_NAME} }));
}

TEST(ToDoListTests, RemoveTaskNormal)
{
	ToDoList list;
	list.AddTask(DATE_NAME, TASK_NAME);
	ASSERT_TRUE(list.GetTasksAmountForDate(DATE_NAME) == 1);
	ASSERT_TRUE(list.GetTasksForDate(DATE_NAME) == std::vector<Task>({ {TASK_NAME} }));
	list.RemoveTask(DATE_NAME, TASK_NAME);
	ASSERT_TRUE(list.GetTasksAmountForDate(DATE_NAME) == 0);
	ASSERT_TRUE(list.GetTasksForDate(DATE_NAME) == std::vector<Task>());
}

TEST(ToDoListTests, LoadBackupNormal)
{
	ToDoList list;
	list.LoadBackup(BACKUP_FILENAME);
	ASSERT_TRUE(list.GetDatesWithTasksAmount() == 5);
	auto datesVec = std::vector<Date>({
		{ 25, 4, 2022 }
		, { 26, 4, 2022 }
		, { 27, 4, 2022 }
		, { 28, 4, 2022 }
		, { 25, 5, 2022 }
		});
	ASSERT_TRUE(list.GetDatesWithTasks() == datesVec);

	auto taskCounter = 1;
	for (const auto& elem : datesVec)
	{
		auto date = Utils::BuildDateStr(elem);
		ASSERT_TRUE(list.GetTasksAmountForDate(date) == taskCounter);
		ASSERT_TRUE(list.GetTasksForDate(date) == std::vector<Task>(taskCounter++, { { "task name" } }));
	}
}

TEST(ToDoListTests, MakeBackupNormal)
{
	ToDoList list;
	list.MakeBackup(CREATE_BACKUP_FILENAME);
	ASSERT_TRUE(std::filesystem::exists(CREATE_BACKUP_FILENAME));
}

int main(int argc, char **argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}