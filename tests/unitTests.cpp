#include "gtest/gtest.h"
#include "ToDoList.h"
#include "easylogging++.h"

INITIALIZE_EASYLOGGINGPP

TEST(ToDoListTests, SimpleUT)
{
	ToDoList list;
}

int main(int argc, char **argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}