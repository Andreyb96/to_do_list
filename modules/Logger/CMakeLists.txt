cmake_minimum_required (VERSION 3.8)

add_library(
	Logger
	${CMAKE_CURRENT_SOURCE_DIR}/easylogging++.cc
	${CMAKE_CURRENT_SOURCE_DIR}/easylogging++.h )