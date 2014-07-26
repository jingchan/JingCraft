cmake_minimum_required(VERSION 3.0 FATAL_ERROR)
# Replace this with a cmake client variable
set(JC_EMSCRIPTEN NO)


if (JC_EMSCRIPTEN)
# Set up emscripten toolchain
	message("Emscripten Build")
	set(EMSCRIPTEN_BUILD 1)
#	set(EMSCRIPTEN_DIR /Users/jingchan/Code/Other/emsdk/emscripten/1.21.0)
	set(EMSCRIPTEN_DIR $ENV{EMSCRIPTEN})
	set(CMAKE_C_COMPILER   ${EMSCRIPTEN_DIR}/emcc)
	set(CMAKE_CXX_COMPILER ${EMSCRIPTEN_DIR}/emcc)
	set(CMAKE_C_FLAGS "-O0 -g -DDEBUG -DEMSCRIPTEN")
	set(CMAKE_CXX_FLAGS "-O0 -g -DDEBUG -DEMSCRIPTEN -DUSE_VBO -std=c++11")
else()
# Set up regular (non-Emscripten) toolchain
	message("Regular Build")
	set(CMAKE_C_FLAGS "-O0 -g -DDEBUG")
	set(CMAKE_CXX_FLAGS "-O0 -g -DDEBUG -std=c++11 -stdlib=libc++")
	include_directories(/usr/local/include)
endif()

project (JingCraft)

#list(APPEND CMAKE_CXX_FLAGS "-L/usr/local/lib")

add_subdirectory(jingcraft)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/Modules/")

set(JC_ADDITIONAL_LIBS "")

if (NOT JC_EMSCRIPTEN)
# SDL
find_package(SDL REQUIRED)
include_directories(${SDL_INCLUDE_DIR})
link_libraries(${SDL_LIBRARY})

# OpenGL
find_package(OpenGL REQUIRED)
include_directories(${OPENGL_INCLUDE_DIR})
link_libraries(${OPENGL_LIBRARIES})
endif()

# Add SDL2
#include(FindPkgConfig)
#pkg_search_module(SDL2 REQUIRED sdl2)
#include_directories(${SDL2_INCLUDE_DIRS})
#link_directories(${SDL2_LIBRARY_DIRS})
#list(APPEND JC_ADDITIONAL_LIBS ${SDL2_LIBRARIES})

# GLM
find_package(GLM REQUIRED)
include_directories(${GLM_INCLUDE_DIR})

# Setup output target
if(JC_EMSCRIPTEN)
	set(JC_OUTFILE main.html)
else()
	set(JC_OUTFILE main)
endif()

set(JC_SOURCE_FILES jingcraft/main.cpp)
list(APPEND JC_ADDITIONAL_LIBS "Renderer")

add_executable(${JC_OUTFILE} ${JC_SOURCE_FILES})
target_link_libraries(${JC_OUTFILE} ${JC_ADDITIONAL_LIBS} ${EXTRA_LIBS})