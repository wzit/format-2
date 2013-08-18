#compiler settings for project
set(CMAKE_CXX_FLAGS "-Wall -Wextra -std=c++11 -stdlib=libc++ ${CMAKE_CXX_FLAGS}")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS} ${CMAKE_CXX_FLAGS_DEBUG} -g -O0")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS} ${CMAKE_CXX_FLAGS_RELEASE} -O5")

# build googletest first
add_subdirectory(googletest)

# build tests
include_directories(${CMAKE_SOURCE_DIR}/tests/googletest/include ${CMAKE_SOURCE_DIR})

set(SRCFILES format_tests.cpp)

add_executable(${PROJECT_TEST_NAME} ${SRCFILES})
target_link_libraries(${PROJECT_TEST_NAME} gtest gtest_main)
add_test(${PROJECT_TEST_NAME} ${PROJECT_TEST_NAME})
add_dependencies(${GTEST_TARGET} ${PROJECT_TEST_NAME})
