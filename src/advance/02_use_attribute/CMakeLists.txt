# file    : CMakeLists.txt
# author  : KeeneChen <keenechen@qq.com>
# date    : 2025.04.29-10:48:57
# details : CMakeLists

project(02_use_attribute)

get_filename_component(PARENT_DIR ${CMAKE_CURRENT_SOURCE_DIR} DIRECTORY)
get_filename_component(PARENT_DIR_NAME ${PARENT_DIR} NAME)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin/${PARENT_DIR_NAME}/${PROJECT_NAME})

add_executable(main main.c attribute_a.c attribute_b.c)