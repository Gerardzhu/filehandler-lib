#ifndef FILEHANDLER_H
#define FILEHANDLER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define ALOGE(...)  do { \
                      printf("\x1b[31m"); \
                      printf(__VA_ARGS__); \
                      printf("\x1b[0m"); \
                    } while(0)
#define ALOGD(...)  do { \
                      printf("\x1b[90m"); \
                      printf(__VA_ARGS__); \
                      printf("\x1b[0m"); \
                    } while(0)
#define ALOGI(...)  do { \
                      printf(__VA_ARGS__); \
                    } while(0)
#define ALOGW(...)  do { \
                      printf("\x1b[33m"); \
                      printf(__VA_ARGS__); \
                      printf("\x1b[0m"); \
                    } while(0)

bool FileInsertTargetlineAfterSourceline(const char *fileName, const char *matchSource, const char *targetSource);
bool FileInsertTargetlineBeforeSourceline(const char *fileName, const char *matchSource, const char *targetSource);

#endif