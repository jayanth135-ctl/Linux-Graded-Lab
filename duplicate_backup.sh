#!/bin/bash

SOURCE_DIR="submissions"
BACKUP_DIR="backup"

REPORT_FILE="report.txt"
ERROR_FILE="errors.log"

mkdir -p "$BACKUP_DIR"

processed=0
duplicated=0
backedup=0

> "$REPORT_FILE"
> "$ERROR_FILE"

for file in "$SOURCE_DIR"/*; do
    if [ -f "$file" ]; then
        ((processed++))

        filename=$(basename "$file")

        if [ -f "$BACKUP_DIR/$filename" ]; then
            cmp -s "$file" "$BACKUP_DIR/$filename"

            if [ $? -eq 0 ]; then
                echo "Duplicate found: $filename" >> "$REPORT_FILE"
                ((duplicated++))
            else
                cp "$file" "$BACKUP_DIR/${filename}_copy" 2>>"$ERROR_FILE"
                ((backedup++))
            fi
        else
            cp "$file" "$BACKUP_DIR/" 2>>"$ERROR_FILE"
            ((backedup++))
        fi
    fi
done

echo "------------------------" >> "$REPORT_FILE"
echo "Files Processed : $processed" >> "$REPORT_FILE"
echo "Duplicate Files : $duplicated" >> "$REPORT_FILE"
echo "Files Backed Up : $backedup" >> "$REPORT_FILE"

echo "Task Completed."
