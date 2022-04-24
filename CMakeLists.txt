cmake_minimum_required (VERSION 3.15)

project(ToDoListMain)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(PROJECT_ROOT_DIR ${CMAKE_CURRENT_SOURCE_DIR})
set(BINARIES_DIR ${PROJECT_ROOT_DIR}/binaries)
set(SCRIPTS_DIR ${PROJECT_ROOT_DIR}/scripts)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${SCRIPTS_DIR})

file(GLOB SOURCES
	"main.cpp")

add_subdirectory(modules)

add_executable(${PROJECT_NAME} ${SOURCES})

target_link_libraries(${PROJECT_NAME} PUBLIC ToDoListLib)

add_subdirectory(tests)