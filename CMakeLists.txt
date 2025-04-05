
cmake_minimum_required(VERSION 3.26)
project(Algos VERSION 1.0)

# Set the variable CMAKE_CXX_STANDARD to 11
# and the variable CMAKE_CXX_STANDARD_REQUIRED to True
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)
# Add debug symbols for gdb
set(CMAKE_BUILD_TYPE Debug)

# Add the src directory where the source files are
add_subdirectory(src)

# Optionally, you can set global include directories
include_directories(${CMAKE_SOURCE_DIR}/headers)