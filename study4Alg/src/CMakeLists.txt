# CMake 最低版本号要求
cmake_minimum_required(VERSION 3.15)

# 项目信息
project(study4Alg)

# 包含头文件
include_directories(./DBase/include)
include_directories(./DBase/include/base)

link_libraries(DBase.lib)
link_directories(./DBase/libs/win32/Debug)

# 查找当前目录下的所有源文件
# 并将名称保存到 SRC_LIST 变量
aux_source_directory(. SRC_LIST)
aux_source_directory(./tree SRC_LIST)

# 指定生成目标
add_executable(${PROJECT_NAME} ${SRC_LIST})
