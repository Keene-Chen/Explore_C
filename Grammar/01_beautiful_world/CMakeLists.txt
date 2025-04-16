# file    : CMakeLists.txt
# author  : KeeneChen <keenechen@qq.com>
# date    : 2025.04.16-22:36:17
# details : CMakeLists

project(01_beautiful_world)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin/Grammar/${PROJECT_NAME})

add_executable(${PROJECT_NAME} hello.c)
