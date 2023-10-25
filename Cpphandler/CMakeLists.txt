cmake_minimum_required(VERSION 3.0)
project(MyFileHandlingProject)

# 设置编译标准为C++14
set(CMAKE_CXX_STANDARD 14)

# 添加可执行文件
add_executable(test main.cpp Insertline/insert.cpp)

# 指定头文件路径
target_include_directories(test PRIVATE ${CMAKE_SOURCE_DIR})

# 链接 Google Test、pthread库
target_link_libraries(test gtest pthread)