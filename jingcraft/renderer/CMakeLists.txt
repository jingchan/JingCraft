cmake_minimum_required(VERSION 3.0 FATAL_ERROR)
project (Renderer)

# set (PROJECT_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/include)
# set (PROJECT_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)

set(RENDERER_SRCS
	${PROJECT_SOURCE_DIR}/renderer.cpp
	${PROJECT_SOURCE_DIR}/renderer2.cpp
	)

# include_directories("${PROJECT_BINARY_DIR}")
# include_directories("${PROJECT_INCLUDE_DIR}")

# add_library(${PROJECT_NAME} SHARED ${RENDERER_SRCS})
add_library(${PROJECT_NAME} ${RENDERER_SRCS})

target_link_libraries(${PROJECT_NAME} World)
