#include <gtest/gtest.h>
#include "filehandler.h"

// 测试插入逻辑的函数
void TestInsertion(const char *testFileName, const char *sourceLine, const char *targetLine, bool before)
{
    // 创建一个测试用的文件
    FILE *testFile = fopen(testFileName, "w");
    fprintf(testFile, "Line 1\n");
    fprintf(testFile, "Line 2\n");
    fclose(testFile);

    // 调用函数，将目标行插入到源行前或后
    if (before)
    {
        EXPECT_TRUE(FileInsertTargetlineBeforeSourceline(testFileName, sourceLine, targetLine));
    }
    else
    {
        EXPECT_TRUE(FileInsertTargetlineAfterSourceline(testFileName, sourceLine, targetLine));
    }

    // 打开文件，检查是否插入成功
    testFile = fopen(testFileName, "r");
    char line[1024];
    bool foundSourceLine = false;
    bool foundTargetLine = false;
    while (fgets(line, sizeof(line), testFile) != NULL)
    {
        if (strstr(line, sourceLine) != NULL)
        {
            foundSourceLine = true;
        }
        if (strstr(line, targetLine) != NULL)
        {
            foundTargetLine = true;
        }
    }
    fclose(testFile);

    // 断言：检查是否找到了源行和目标行
    EXPECT_TRUE(foundSourceLine);
    EXPECT_TRUE(foundTargetLine);

    // 清理测试用的文件
    remove(testFileName);
}

TEST(FileInsertTargetline, TestInsertionAfter)
{
    TestInsertion("test_file.txt", "Line 2", "Line 3", false);
}

TEST(FileInsertTargetline, TestInsertionBefore)
{
    TestInsertion("test2_file.txt", "Line 2", "Line 3", true);
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}