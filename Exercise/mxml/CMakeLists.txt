cmake_minimum_required(VERSION 3.0.0)
project(MiniXML VERSION 0.1.0)

find_library(LIB_MiniXML libmxml.so /usr/local/lib)
message(STATUS "LIB_MiniXML = ${LIB_MiniXML}")
find_library(LIB_kc libkc.so /usr/local/lib)
message(STATUS "LIB_kc = ${LIB_kc}")

add_executable(construct_data src/construct_data.c)
target_link_libraries(construct_data ${LIB_kc} ${LIB_MiniXML})
add_executable(parse_data src/parse_data.c)
target_link_libraries(parse_data ${LIB_kc} ${LIB_MiniXML})
