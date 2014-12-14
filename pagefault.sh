#!/bin/sh

#rm /tmp/file_list.csv
dd if=../file_list.csv of=/tmp/file_list.csv bs=4M iflag=direct oflag=direct
./pagefault.out
rm /tmp/file_list.csv
