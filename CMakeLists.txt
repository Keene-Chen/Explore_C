# file    : CMakeLists.txt
# author  : KeeneChen <keenechen@qq.com>
# date    : 2025.04.16-21:55:16
# details : CMakeLists

cmake_minimum_required(VERSION 3.28...4.0)

# 设置语言标准,一定要在 project() 之前配置
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 设置编译器
# set(COMPILE_PATH /usr/bin)
# set(CMAKE_C_COMPILER ${COMPILE_PATH}/clang)
# set(CMAKE_CXX_COMPILER ${COMPILE_PATH}/clang++)

# 设置编译缓存
# set(CMAKE_C_COMPILER_LAUNCHER "ccache")
# set(CMAKE_CXX_COMPILER_LAUNCHER "ccache")
project(
  Explore_C
  VERSION 0.0.1
  LANGUAGES C CXX
  HOMEPAGE_URL "http://gitlab.keenechen.cn/Explore_Code/Explore_C"
  DESCRIPTION "Explore C"
)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")
include(kc_conf)

# 添加子目录
add_subdirectory(Grammar)