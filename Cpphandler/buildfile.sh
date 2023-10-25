#!/bin/bash

# 项目目录
project_dir=$(dirname "$0")

# 进入项目目录
cd "$project_dir"

# 创建一个build目录并进入
mkdir -p build
cd build

# 使用CMake生成构建系统
cmake ..

# 编译项目
make

# 返回到项目根目录
cd ..