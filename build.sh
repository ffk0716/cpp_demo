#!/bin/bash
set -eux

git clean -ffdx
mkdir -p b
cd b
cmake ..
make -j$(nproc)
ctest -j$(nproc)
