#!/bin/bash
read -p "Enter a filename to check: " FILE

if [ -e "$FILE" ]; then
    echo "$FILE exists."
    ls -l "$FILE"
else
    echo "$FILE does not exist."
fi
