message("<FindGOOGLE_TEST.cmake>")

set(LIBNAME GoogleTest)

if((NOT ${OS} STREQUAL "win") AND (NOT ${OS} STREQUAL "linux"))
	message(ERROR "OS ${OS} do not supported")
	return()
endif()

message(STATUS "Building GoogleTest...")
execute_process(COMMAND python ${SCRIPTS_DIR}/build_google_tests.py
  WORKING_DIRECTORY ${BINARIES_DIR}
  RESULT_VARIABLE BUILD_GOOGLE_TEST_PYTHON_RESULT)

if (NOT ${BUILD_GOOGLE_TEST_PYTHON_RESULT} EQUAL 0)
    execute_process(COMMAND python3 ${SCRIPTS_DIR}/build_google_tests.py
		WORKING_DIRECTORY ${BINARIES_DIR}
  	RESULT_VARIABLE BUILD_GOOGLE_TEST_PYTHON3_RESULT)
    if (NOT ${BUILD_BUILD_GOOGLE_TEST_PYTHON3_RESULT} EQUAL 0)
    	message( FATAL_ERROR "Failed while building GoogleTest" )
    endif()
endif()

if (WIN32)
	if(CMAKE_BUILD_TYPE MATCHES Release)
		set (LIB_NAMES_LIST gmock gmock_main gtest gtest_main)
	else()
		set (LIB_NAMES_LIST gmockd gmock_maind gtestd gtest_maind)
	endif()
	set (LIB_PATH "${BINARIES_DIR}/lib/${LIBNAME}/${CMAKE_BUILD_TYPE}")
else()
	set (LIB_NAMES_LIST gmock gmock_main gtest gtest_main)
	set (LIB_PATH "${BINARIES_DIR}/lib/${LIBNAME}")
endif()

list(APPEND GOOGLE_TEST_LIBS "")

find_path(GOOGLE_TEST_INCLUDE_DIR gtest/gtest.h
	PATHS ${BINARIES_DIR}/include/${LIBNAME}
)

foreach(NAME ${LIB_NAMES_LIST})

	find_library(${NAME}_LIBRARY
		NAMES ${NAME}
		PATHS ${LIB_PATH}
	)

	list(APPEND GOOGLE_TEST_LIBS ${${NAME}_LIBRARY})

endforeach()

message("</FindGOOGLE_TEST.cmake>")
