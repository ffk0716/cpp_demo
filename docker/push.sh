#!/bin/bash
set -eux

cur_dir=$(cd $(dirname $0); pwd -P)
cd ${cur_dir}

./build.sh

source ./version.sh

docker push registry.gitlab.com/ffk0716/cpp_demo:$VERSION
