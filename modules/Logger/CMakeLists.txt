cmake_minimum_required (VERSION 3.15)

PROJECT(Logger)

add_library(
	${PROJECT_NAME}
	${CMAKE_CURRENT_SOURCE_DIR}/easylogging++.cc
	${CMAKE_CURRENT_SOURCE_DIR}/easylogging++.h )

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})