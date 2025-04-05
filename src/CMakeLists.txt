cmake_minimum_required(VERSION 3.26)
project(Algos VERSION 1.0)

# Add the source files (all .cpp files including main.cpp)
set(SOURCES
    main.cpp
)

# Add the executable target, linking the sources together
add_executable(algos ${SOURCES})