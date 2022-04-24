cmake_minimum_required (VERSION 3.15)

project(ToDoListTests)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set (BINARY_DIR binaries)

file(MAKE_DIRECTORY ${BINARY_DIR})
execute_process(COMMAND ${CMAKE_COMMAND} -E make_directory ${BINARY_DIR})

message(STATUS "Loading Google Tests framework...")
execute_process(COMMAND python ${PROJECT_ROOT_DIR}/scripts/build_google_tests.py
  WORKING_DIRECTORY ${PROJECT_ROOT_DIR}/binaries
  RESULT_VARIABLE COMMON_LIBS_DOWNLOAD_RESULT)

if (NOT ${COMMON_LIBS_DOWNLOAD_RESULT} EQUAL 0)
    execute_process(COMMAND python3 ${PROJECT_ROOT_DIR}/scripts/build_google_tests.py
    WORKING_DIRECTORY ${PROJECT_ROOT_DIR}/binaries
    RESULT_VARIABLE COMMON_LIBS_DOWNLOAD_PYTHON3_RESULT)
    if (NOT ${COMMON_LIBS_DOWNLOAD_PYTHON3_RESULT} EQUAL 0)
        message( FATAL_ERROR "Failed while downloading common libs" )
    endif()
endif()

file(GLOB SOURCES
	"unitTests.cpp")

add_executable(${PROJECT_NAME} ${SOURCES})

target_link_libraries(${PROJECT_NAME} PUBLIC ToDoListLib)