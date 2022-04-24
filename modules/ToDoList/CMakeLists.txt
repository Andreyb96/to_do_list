cmake_minimum_required (VERSION 3.15)

project(ToDoListLib)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

file(GLOB SOURCES
	"src/*.cpp")

file(GLOB HEADERS
	"include/*.h")


createLib(${PROJECT_NAME} 
			STATIC
			HEADERS ${HEADERS} 
			SOURCES ${SOURCES}
			MODULES Logger Utils)

target_include_directories(${PROJECT_NAME} PUBLIC "include/")
target_include_directories(${PROJECT_NAME} PUBLIC ${MODULES_DIR}/Utils/include)