cmake_minimum_required (VERSION 3.15)

project(ToDoListMain)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(PROJECT_ROOT_DIR ${CMAKE_CURRENT_SOURCE_DIR})
set(BINARIES_DIR ${PROJECT_ROOT_DIR}/binaries)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_CURRENT_SOURCE_DIR}/scripts ${BINARIES_DIR}/lib/GoogleTest/Debug)

file(GLOB SOURCES
	"main.cpp")

add_subdirectory(modules)

add_executable(${PROJECT_NAME} ${SOURCES})

target_link_libraries(${PROJECT_NAME} PUBLIC ToDoListLib Logger)

add_subdirectory(tests)