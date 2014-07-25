cmake_minimum_required(VERSION 3.0 FATAL_ERROR)
project(jingcraft_exe)

add_subdirectory(renderer)
add_subdirectory(world)

# include_directories("${PROJECT_INCLUDE_DIR}")
# include_directories("${PROJECT_SOURCE_DIR}")

set(JC_SOURCE_FILES main.cpp)
add_executable(jingcraft ${JC_SOURCE_FILES})

target_link_libraries(jingcraft renderer)

