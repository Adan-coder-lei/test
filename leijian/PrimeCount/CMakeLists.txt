#CMake最低版本号要求
cmake_minimum_required(VERSION 2.8)
#项目信息
project(PrimeCount)
#添加标准库名称，这里需要用到math的库
LINK_LIBRARIES(m)
#指定生成目标
add_executable(PrimeCount PrimeCount.c)