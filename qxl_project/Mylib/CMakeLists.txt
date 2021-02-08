# 查找当前目录下的所有源文件将名称保存到 DIR_LIST 变量

aux_source_directory(. DIR_LIST)


# 设置链接库链接

SET(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/LIB)


# 添加链接库

add_library(Mylib ${DIR_LIST})
