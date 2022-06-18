cmake_minimum_required (VERSION 3.0) 
project(tinymuduo)

# 配置编译选项
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -std=c++11")

set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)

aux_source_directory(./src SRC_LIST)

include_directories(${PROJECT_SOURCE_DIR}/include)

add_library(tinymuduo SHARED ${SRC_LIST})
