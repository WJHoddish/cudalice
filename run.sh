#!/bin/bash
clear

mkdir -p build && cd build
rm -rf *

cmake -DCMAKE_BUILD_TYPE=Release \
    .. && make -j

# run
./cudalice_test
