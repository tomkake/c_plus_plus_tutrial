cmake_minimum_required(VERSION 3.5)
project(cmake_tutrial)
set(SOURCEFILE main.cpp)
set(SHAREDLIB "lib/")
set(SHAREDHEADER "include/")

add_library(test SHARED test.cpp)
add_executable(main ${SOURCEFILE})

target_include_directories(test PUBLIC ${SHAREDHEADER})

target_link_libraries(main PRIVATE test)
