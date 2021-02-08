# 设置动态库输出路径

include_directories(${project_source_dir}/Mylib)


# 设置可执行文件输出路径

SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/../bin)


# 查看当前目录下的源文件

aux_source_directory(./ dir_src)


# 生成可执行文件homework

add_executable(homework ${dir_src})

# 链接动态库

target_link_libraries(homework Mylib)