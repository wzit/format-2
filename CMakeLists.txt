cmake_minimum_required(VERSION 2.8.8)

project(format)
#Add the project's cmake directory to the module path



# Testing with the Google Test framework
enable_testing()
set(PROJECT_TEST_NAME "${CMAKE_PROJECT_NAME}_tests")
set(GTEST_TARGET "tests")
add_custom_target(${GTEST_TARGET} 
  COMMAND "tests/${PROJECT_TEST_NAME}"
COMMENT "Running unit tests with Google Test Framework" VERBATIM)
add_subdirectory(tests)

#Documentation generation with Doxygen
find_package(Doxygen)
if (DOXYGEN_FOUND)
	set(DOXYGEN_TARGET "doc")
	add_custom_target(${DOXYGEN_TARGET}
	COMMAND ${DOXYGEN_EXECUTABLE} ${CMAKE_SOURCE_DIR}/doc/Doxyfile
	COMMENT "Generating API Documentation with Doxygen" VERBATIM)
endif()	
