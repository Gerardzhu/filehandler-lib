#!/bin/bash

if [ "$#" -ne 3 ]; then
    echo "Usage: $0 filename matchSource targetSource"
    exit 1
fi

filename="$1"
matchSource="$2"
targetSource="$3"

if [ -f "$filename" ]; then
    # 创建临时文件来存储修改后的内容
    tmpfile=$(mktemp)

    foundmatchSource=0
    foundtargetSource=0

    while IFS= read -r line; do
        if [[ "$line" == *"$matchSource"* ]]; then
            foundmatchSource=1
        fi

        if [[ "$line" == *"$targetSource"* ]]; then
            foundtargetSource=1
        fi

        echo "$line" >> "$tmpfile"
    done < "$filename"

    if [ "$foundmatchSource" -eq 1 ] && [ "$foundtargetSource" -eq 0 ]; then
        # 插入目标行
        echo "$targetSource" >> "$tmpfile"
        mv "$tmpfile" "$filename"
        echo "Added targetSource --> $targetSource to $filename"
    else
        rm "$tmpfile"
    fi
else
    echo "Error: Unable to open the configuration file $filename."
fi
