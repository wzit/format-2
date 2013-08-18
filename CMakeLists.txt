cmake_minimum_required(VERSION 2.8.8)

project(format)

# Testing with the Google Test framework
enable_testing()
set(PROJECT_TEST_NAME "${CMAKE_PROJECT_NAME}_tests")
set(GTEST_TARGET "tests")
add_custom_target(${GTEST_TARGET} 
  COMMAND "tests/${PROJECT_TEST_NAME}"
COMMENT "Running unit tests with Google Test Framework" VERBATIM)
add_subdirectory(tests)
