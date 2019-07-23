#!/bin/bash
set -eux

cur_dir=$(cd $(dirname $0); pwd -P)
cd ${cur_dir}

source ./version.sh

docker build -t \
    registry.gitlab.com/ffk0716/cpp_demo:$VERSION \
    .
