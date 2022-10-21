cmake_minimum_required(VERSION 3.1)

set(THREADS_PREFER_PTHREAD_FLAG ON)

# Set the project here.
project(Laboratory2)

# Locate GTest
find_package(GTest REQUIRED)
find_package(Threads REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
 
# Link runTests with what we want to test and the GTest and pthread library
add_executable(runTests tests.cpp)
target_link_libraries(runTests ${GTEST_LIBRARIES} Threads::Threads)
