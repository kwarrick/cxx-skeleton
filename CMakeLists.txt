cmake_minimum_required (VERSION 3.9.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

project (foo CXX)

include_directories(include)
add_library(bar src/bar.cpp)
add_executable(foo src/foo.cpp src/bar.cpp)

set(CXXFLAGS "-Wall -Werror -fsanitize=address")
set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} ${CXXFLAGS}")

enable_testing()
add_subdirectory(tests)
