cmake_minimum_required (VERSION 3.15)

project(ToDoListLib)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

file(GLOB SOURCES
	"src/*.cpp")

file(GLOB HEADERS
	"include/*.h")

add_library(${PROJECT_NAME} ${SOURCES} ${HEADERS})

target_link_libraries(${PROJECT_NAME} PUBLIC Logger)
target_include_directories(${PROJECT_NAME} PUBLIC "include/")