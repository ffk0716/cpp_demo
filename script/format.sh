#!/bin/bash
set -exu

cur_dir=$(cd $(dirname $0); pwd -P)
cd ${cur_dir}/..

# commit before format
git diff --exit-code

if [ ! -d build ]; then
    mkdir -p build
    pushd build
    cmake ..
    popd
fi
run-clang-tidy -p ./build -fix -format
find . -regex '.*\.\(cpp\|h\|cxx\)' -exec clang-format -i {} \;
git diff --exit-code
