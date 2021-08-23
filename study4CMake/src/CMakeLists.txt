# CMake 最低版本号要求
cmake_minimum_required(VERSION 3.15)

# 项目信息
project(myCMake)

# 查找当前目录下的所有源文件
# 并将名称保存到 SRC_LIST 变量
aux_source_directory(. SRC_LIST)

# 添加 math 子目录
add_subdirectory(math)

# 指定生成目标
add_executable(${PROJECT_NAME} ${SRC_LIST})

# 添加链接库
target_link_libraries(${PROJECT_NAME} MathFunctions)
