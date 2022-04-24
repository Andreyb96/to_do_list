#include "gtest/gtest.h"
#include "ToDoList.h"
#include "easylogging++.h"
#include "Utils.h"

INITIALIZE_EASYLOGGINGPP

constexpr auto TASK_NAME = "task_name";

TEST(ToDoListTests, AddTaskForToday)
{
	ToDoList list;
	list.AddTaskForToday(TASK_NAME);
	ASSERT_TRUE(list.GetTasksAmountForDate("") == 1);
}

int main(int argc, char **argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}