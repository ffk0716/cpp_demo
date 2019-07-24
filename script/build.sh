#!/bin/bash
set -eux

cur_dir=$(cd $(dirname $0); pwd -P)
cd ${cur_dir}/..

git clean -ffdx
mkdir -p build
pushd build
cmake ..
make -j$(nproc)
ctest -j$(nproc)
popd
