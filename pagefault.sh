#!/bin/sh

dd if=/dev/urandom of=/tmp/pagefault_input oflag=direct bs=4M count=1

./pagefault.out /tmp/pagefault_input

