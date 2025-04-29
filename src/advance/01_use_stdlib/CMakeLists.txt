# file    : CMakeLists.txt
# author  : KeeneChen <keenechen@qq.com>
# date    : 2025.04.29-11:25:45
# details : CMakeLists

project(01_use_stdlib)

get_filename_component(PARENT_DIR ${CMAKE_CURRENT_SOURCE_DIR} DIRECTORY)
get_filename_component(PARENT_DIR_NAME ${PARENT_DIR} NAME)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin/${PARENT_DIR_NAME}/${PROJECT_NAME})

# 获取当前文件夹下的所有 .c 文件
file(GLOB C_FILES *.c)
# 遍历所有 .c 文件并生成可执行文件
foreach(C_FILE ${C_FILES})
    # 获取文件名(不含扩展名)
    get_filename_component(EXEC_NAME ${C_FILE} NAME_WE)

    # 添加可执行文件目标
    add_executable(${EXEC_NAME} ${C_FILE})
endforeach()
