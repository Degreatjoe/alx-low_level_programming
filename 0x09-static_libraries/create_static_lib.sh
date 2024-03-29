#!/bin/bash

# Find all .c files in the current directory
C_FILES=$(find . -maxdepth 1 -name "*.c")

# Compile each .c file into object files
for file in $C_FILES; do
    gcc -c $file -o ${file%.c}.o
done

# Create the static library
ar rcs liball.a *.o

# Clean up object files
rm -f *.o

exit 0
