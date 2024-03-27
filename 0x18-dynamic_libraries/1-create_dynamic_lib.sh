#!/bin/bash

# Find all .c files in the current directory
c_files=$(find . -maxdepth 1 -type f -name "*.c")

# Check if any .c files are found
if [ -z "$c_files" ]; then
    echo "No .c files found in the current directory."
    exit 1
fi

# Compile all .c files into a dynamic library named liball.so
gcc -shared -fPIC -o liball.so $c_files

# Check if compilation was successful
if [ $? -eq 0 ]; then
    exit 0
else
    echo "Error: Compilation failed."
    exit 1
fi
