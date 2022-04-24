include(GoogleTest)

cmake_minimum_required (VERSION 3.15)

project(ToDoListTests)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

file(MAKE_DIRECTORY ${BINARIES_DIR})
execute_process(COMMAND ${CMAKE_COMMAND} -E make_directory ${BINARIES_DIR})

file(GLOB SOURCES
	"unitTests.cpp")

createExecutable(${PROJECT_NAME}
		SOURCES ${SOURCES}
		MODULES ToDoListLib
		LIBS GOOGLE_TEST)

target_include_directories(${PROJECT_NAME} PUBLIC ${BINARIES_DIR}/include/GoogleTest)

gtest_add_tests(TARGET ${PROJECT_NAME})