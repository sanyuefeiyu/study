# 查找当前目录下的所有源文件
# 并将名称保存到 SUB_SRC_LIST 变量
aux_source_directory(. SUB_SRC_LIST)

# 生成链接库
add_library(sub STATIC ${SUB_SRC_LIST})
