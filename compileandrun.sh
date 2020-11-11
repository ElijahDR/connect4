#!/bin/bash
g++ -Werror program.cc -o program.o
if [[ $? == 0 ]]; then
    ./program.o
fi
