#!/bin/bash
# Counts files by type (extension) in a directory and logs results.
DIR="${1:-.}"
LOG="file-count-log.txt"

echo "File type count for: $DIR" > "$LOG"
echo "Generated: $(date)" >> "$LOG"
echo "---" >> "$LOG"

find "$DIR" -maxdepth 1 -type f | sed -n 's/.*\.\([^.\/]*\)$/\1/p' | sort | uniq -c | sort -rn >> "$LOG"

cat "$LOG"
