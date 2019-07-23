#!/bin/bash
set -exu

cur_dir=$(cd $(dirname $0); pwd -P)

source ${cur_dir}/version.sh

docker run \
    --rm \
    -it \
    -v $HOME:$HOME \
    -w ${PWD} \
    registry.gitlab.com/ffk0716/cpp_demo:$VERSION \
    $@
