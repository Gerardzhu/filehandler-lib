# 文件处理程序库

这是我手写的API集成库，用于文件操作

**上次更新时间：2023年10月26日**

# 2023-10-26发布

## 更新
-修复错误：当targetsource已经存在时，不执行插入操作；
-Shell脚本、C语言和Python脚本都实现了在文件匹配行前后插入一行的操作

# 2023-10-25发布

## 更新

- 在谷歌测试的介绍部分添加了介绍及其用法
- 此API仅更新了C++部分
- 添加了twos-api：在与源内容匹配的行之前和之后插入目标内容。
- Api命名：
```
bool FileInsertTargetlineBeforeSourceline（const char*fileName，const char*matchSource，const char*targetSouce）。
bool FileInsertTargetlineAfterSourceline（const char*fileName，const char*matchSource，const char*targetSouce）。
```