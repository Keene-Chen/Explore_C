# file    : CMakeLists.txt
# author  : KeeneChen <keenechen@qq.com>
# date    : 2025.04.16-22:36:17
# details : CMakeLists

project(01_beautiful_world)

get_filename_component(PARENT_DIR ${CMAKE_CURRENT_SOURCE_DIR} DIRECTORY)
get_filename_component(PARENT_DIR_NAME ${PARENT_DIR} NAME)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin/${PARENT_DIR_NAME}/${PROJECT_NAME})

add_executable(${PROJECT_NAME} hello.c)
