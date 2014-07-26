cmake_minimum_required(VERSION 3.0 FATAL_ERROR)
project(Jingcraft_exe)


# include_directories("${PROJECT_INCLUDE_DIR}")
# include_directories("${PROJECT_SOURCE_DIR}")
# include_directories("${PROJECT_SOURCE_DIR}/renderer/include")
# include_directories("${PROJECT_SOURCE_DIR}")
include_directories(".")

add_subdirectory(renderer)
add_subdirectory(world)