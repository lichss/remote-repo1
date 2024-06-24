# 最低版本需求
cmake_minimum_required(VERSION 3.10)

#添加项目
project(Workers)

#设置c艹标准
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

#指定头文件包含目录
include_directories(${PROJECT_SOURCE_DIR}/inc )

#收集源文件
file(GLOB SOURCES "src/*.cpp")


#添加可执行文件
add_executable(Workers ${SOURCES})



