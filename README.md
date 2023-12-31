# filehandler-lib
This is my handwritten API integrated library for file operations

**Last Updated: October 26, 2023**

# Release on 2023-10-26

## Updates
- Fix bug: Do not perform insert operation when targetsource already exists;
- Shell scripts, C language, and Python scripts all implement the operation of inserting a line before and after a file matching line

# Release on 2023-10-25

## Updates

- Added an introduction to the introductory section of googletest and its usage
- This API only updated the C++part
- Added twos api: Insert the target content before and after a line that matches the source content.
- Api named: 

```
bool FileInsertTargetlineBeforeSourceline(const char * fileName, const char * matchSource, const char *targetSouce).

bool FileInsertTargetlineAfterSourceline(const char * fileName, const char * matchSource, const char *targetSouce).
```