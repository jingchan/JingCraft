cmake_minimum_required(VERSION 3.0 FATAL_ERROR)

# setup emscripten toolchain
SET(EMSCRIPTEN_BUILD 1)
SET(EMSCRIPTEN_DIR /Users/jingchan/Code/Other/emsdk/emscripten/1.21.0)
SET(CMAKE_C_COMPILER   ${EMSCRIPTEN_DIR}/emcc)
SET(CMAKE_CXX_COMPILER ${EMSCRIPTEN_DIR}/emcc)
SET(CMAKE_C_FLAGS "-O0 -g -DDEBUG -DEMSCRIPTEN")
SET(CMAKE_CXX_FLAGS "-O0 -g -DDEBUG -DEMSCRIPTEN -DUSE_VBO -v")

project (JingCraft)

#set(CMAKE_CXX_FLAGS "-L/usr/local/lib")

add_subdirectory(jingcraft)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/Modules/")

set(JC_LIBS "")

# Add SDL2
#find_package (SDL2 REQUIRED)
#include_directories(${SDL2_INCLUDE_DIRS})
#link_directories(${SDL2_LIBRARY_DIRS})
#set(JC_LIBS ${JC_LIBS} ${SDL2_LIBRARIES})

INCLUDE(FindPkgConfig)
PKG_SEARCH_MODULE(SDL2 REQUIRED sdl2)
INCLUDE_DIRECTORIES(${SDL2_INCLUDE_DIRS})
link_directories(${SDL2_LIBRARY_DIRS})
list(APPEND JC_LIBS ${SDL2_LIBRARIES})

# Setup output target
set(JC_OUTFILE main.html)
set(JC_SOURCE_FILES jingcraft/main.cpp)
list(APPEND JC_LIBS "Renderer")

add_executable(${JC_OUTFILE} ${JC_SOURCE_FILES})
target_link_libraries(${JC_OUTFILE} ${JC_DEPS} ${JC_LIBS})
