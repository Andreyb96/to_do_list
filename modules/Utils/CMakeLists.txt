cmake_minimum_required (VERSION 3.15)

PROJECT(Utils)

file(GLOB SOURCES
	"src/*.cpp")

file(GLOB HEADERS
	"include/*.h")

createLib(${PROJECT_NAME} 
			STATIC
			HEADERS ${HEADERS} 
			SOURCES ${SOURCES})

target_include_directories(${PROJECT_NAME} PUBLIC "include")