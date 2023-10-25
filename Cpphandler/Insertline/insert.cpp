#include "filehandler.h"

bool FileInsertTargetlineAfterSourceline(const char *filename, const char *matchSource, const char *targetSource)
{
    FILE *file = fopen(filename, "r+");

    if (file)
    {
        char line[256];
        int foundmatchSource = 0; // 是否找到matchSource行

        char linesBeforematchSource[1000][256]; // 存储matchSource行之前的内容
        char linesAftermatchSource[1000][256];  // 存储matchSource行之后的内容
        int numLinesBeforematchSource = 0;
        int numLinesAftermatchSource = 0;

        // 读取文件内容，查找matchSource行
        while (fgets(line, sizeof(line), file))
        {
            if (strstr(line, matchSource) != NULL)
            {
                foundmatchSource = 1;
                if (numLinesBeforematchSource < 1000)
                {
                    strcpy(linesBeforematchSource[numLinesBeforematchSource], line);
                    numLinesBeforematchSource++;
                }
            }
            else
            {
                if (foundmatchSource)
                {
                    if (numLinesAftermatchSource < 1000)
                    {
                        strcpy(linesAftermatchSource[numLinesAftermatchSource], line);
                        numLinesAftermatchSource++;
                    }
                }
                else
                {
                    if (numLinesBeforematchSource < 1000)
                    {
                        strcpy(linesBeforematchSource[numLinesBeforematchSource], line);
                        numLinesBeforematchSource++;
                    }
                }
            }
        }

        // 如果未找到targetSource行，且已找到matchSource行，则添加它
        if (foundmatchSource)
        {
            // 重新定位到文件开头
            fseek(file, 0, SEEK_SET);

            // 将linesBeforematchSource写回文件
            for (int i = 0; i < numLinesBeforematchSource; i++)
            {
                fputs(linesBeforematchSource[i], file);
            }

            fprintf(file, "%s\n", targetSource); // 修正此处的fprintf调用
            // 将linesAftermatchSource写回文件
            for (int i = 0; i < numLinesAftermatchSource; i++)
            {
                fputs(linesAftermatchSource[i], file);
            }

            ALOGD("Added targetSource --> %s to %s\n", targetSource, filename);
        }

        fclose(file);
        return true;
    }
    else
    {
        ALOGE("Error: Unable to open the configuration file %s.\n", filename);
        return false;
    }
}


bool FileInsertTargetlineBeforeSourceline(const char *filename, const char *matchSource, const char *targetSource) {
    FILE *file = fopen(filename, "r+");

    if (file) {
        char line[256];
        int foundmatchSource = 0;               // 是否找到matchSource行

        char linesBeforematchSource[1000][256]; // 存储matchSource行之前的内容
        int numLinesBeforematchSource = 0;

        // 读取文件内容，查找matchSource行
        while (fgets(line, sizeof(line), file)) {
            if (strstr(line, matchSource) != NULL) {
                foundmatchSource = 1;
                break;
            }
            if (numLinesBeforematchSource < 1000) {
                strcpy(linesBeforematchSource[numLinesBeforematchSource], line);
                numLinesBeforematchSource++;
            }
        }

        // 如果找到matchSource行，将targetSource插入到该行之前
        if (foundmatchSource) {
            // 重新定位到文件开头
            fseek(file, 0, SEEK_SET);

            // 将linesBeforematchSource写回文件
            for (int i = 0; i < numLinesBeforematchSource; i++) {
                fputs(linesBeforematchSource[i], file);
            }

            // 插入目标行
            fprintf(file, "%s\n", targetSource);

            // 将matchSource行写回文件
            fprintf(file, "%s\n", matchSource);

            // 继续写入剩余的文件内容
            while (fgets(line, sizeof(line), file)) {
                fputs(line, file);
            }

            ALOGD("Inserted targetSource --> %s before %s in %s\n", targetSource, matchSource, filename);
        }

        fclose(file);
        return true;
    } else {
        ALOGE("Error: Unable to open the configuration file %s.\n", filename);
        return false;
    }
}
