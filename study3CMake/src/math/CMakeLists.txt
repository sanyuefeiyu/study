# 查找当前目录下的所有源文件
# 并将名称保存到 MATH_SRC_LIST 变量
aux_source_directory(. MATH_SRC_LIST)
aux_source_directory(./add MATH_SRC_LIST)

# 添加 math 子目录
add_subdirectory(div)
add_subdirectory(sub)

# 生成链接库
add_library(MathFunctions STATIC ${MATH_SRC_LIST})

target_link_libraries(MathFunctions div sub)
