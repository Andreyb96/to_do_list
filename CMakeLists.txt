cmake_minimum_required (VERSION 3.15)

project(ToDoList)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

file(GLOB SOURCES
	"src/*.cpp")

file(GLOB HEADERS
	"include/*.h")

include_directories("include/")

add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})
