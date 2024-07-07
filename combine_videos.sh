#!/bin/bash

# Create a file list
echo "Creating file list..."
rm -f filelist.txt
for file in $(ls output_chunk_*.webm | sort -V); do
    echo "file '$file'" >> filelist.txt
done

# Combine videos using FFmpeg
echo "Combining videos..."
ffmpeg -f concat -safe 0 -i filelist.txt -c copy combine_output.webm

echo "Combined video saved as combined_output.webm"
