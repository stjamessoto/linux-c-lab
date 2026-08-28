#!/bin/bash
# Automates directory listing for the advanced command-line task.
TARGET="${1:-.}"
echo "Directory listing for: $TARGET"
echo "Generated: $(date)"
echo "---"
tree -L 2 "$TARGET"
