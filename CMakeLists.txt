cmake_minimum_required(VERSION 3.10)
project(your_project)

# Set the directories for header files and source files
set(INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/gtest)
set(SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)

# Include the directory containing header files
include_directories(${INCLUDE_DIR})

# Add your source files
file(GLOB SRC_FILES ${SRC_DIR}/*.cpp)

# Create an executable for your project
add_executable(your_executable ${SRC_FILES})

# Locate and include Google Test
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# Add your test files
file(GLOB TEST_FILES ${CMAKE_CURRENT_SOURCE_DIR}/test/*.cpp)

# Create an executable for your tests
add_executable(your_tests ${TEST_FILES})

# Link your test executable with Google Test
target_link_libraries(your_tests ${GTEST_BOTH_LIBRARIES} pthread)