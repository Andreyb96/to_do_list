function(exportCommonLibs)

	cmake_parse_arguments(EXPORT_COMMON_LIBS "" "COMMON_LIBS_TARGET" "LIB_NAMES" ${ARGV})

	if("COMMON_LIBS_TARGET" STREQUAL "")
		set(COMMON_LIBS_TARGET ${PROJECT_NAME})
	endif()

	foreach(LIB_NAME ${EXPORT_COMMON_LIBS_LIB_NAMES})
		find_package(${LIB_NAME}  REQUIRED)
		set(INCLUDE_LIST "${INCLUDE_LIST};${${LIB_NAME}_INCLUDE_DIR}")
		set(LIBS_LIST "${LIBS_LIST};${${LIB_NAME}_LIBS}")
	endforeach()

	list(LENGTH INCLUDE_LIST INCLUDE_LIST_SIZE)
	list(LENGTH LIBS_LIST LIBS_LIST_SIZE)

	if(${INCLUDE_LIST_SIZE} EQUAL 0 OR ${LIBS_LIST_SIZE} EQUAL 0)
		message("Empty include dirs or libs list")
		return()
	endif()

	target_include_directories(${EXPORT_COMMON_LIBS_COMMON_LIBS_TARGET} PUBLIC ${INCLUDE_LIST})

	target_link_libraries(${EXPORT_COMMON_LIBS_COMMON_LIBS_TARGET} ${LIBS_LIST})

endfunction(exportCommonLibs)

function(link_modules TARGET)
    if("${TARGET}" STREQUAL "")
        set(TARGET ${PROJECT_NAME})
    endif()

    if (ARGN)
        foreach(ARG ${ARGN})
            target_include_directories(${PROJECT_NAME} PUBLIC ${${ARG}_SOURCE_DIR}/src)
        endforeach()
        list(REMOVE_DUPLICATES ARGN)
        target_link_libraries(${TARGET} ${ARGN} ${CMAKE_DL_LIBS})
    endif()
endfunction(link_modules)

function(createExecutable TARGET_NAME)
        set(MULTI_VALUE_ARGS HEADERS SOURCES LIBS MODULES)
	set(MULTI_VALUE_ARGS HEADERS SOURCES LIBS MODULES)
	cmake_parse_arguments(OPTIONS "" "" "${MULTI_VALUE_ARGS}" ${ARGN})

	message(STATUS "Target: ${TARGET_NAME}")
	message(STATUS "Headers: ${OPTIONS_HEADERS}")
	message(STATUS "Sources: ${OPTIONS_SOURCES}")
	message(STATUS "Link libraries: ${OPTIONS_LIBS}")
	message(STATUS "Modules: ${OPTIONS_MODULES}")
		  
	add_executable(${TARGET_NAME} ${OPTIONS_HEADERS} ${OPTIONS_SOURCES})
	link_modules(${TARGET_NAME} ${OPTIONS_MODULES})

	exportCommonLibs(COMMON_LIBS_TARGET ${TARGET_NAME} LIB_NAMES ${OPTIONS_LIBS})
endfunction(createExecutable)
