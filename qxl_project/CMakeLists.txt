# CMake 最低版本号要求

cmake_minimum_required (VERSION 2.8)

# 项目信息

project (homework)

############# Use message function to print information ############
message(STATUS "CMake version: ${CMAKE_VERSION}")

# 添加链接库路径
add_subdirectory(./Mylib)

# 添加源文件路径
add_subdirectory(./source)

