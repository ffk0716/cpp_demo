FROM ubuntu:18.04
#FROM rikorose/gcc-cmake:gcc-7

RUN apt-get update && \
        apt-get install -y \
        build-essential \
        wget

RUN wget https://github.com/Kitware/CMake/releases/download/v3.14.3/cmake-3.14.3-Linux-x86_64.sh \
        -q -O /tmp/cmake-install.sh \
        && chmod u+x /tmp/cmake-install.sh \
        && mkdir /usr/bin/cmake \
        && /tmp/cmake-install.sh --skip-license --prefix=/usr/bin/cmake \
        && rm /tmp/cmake-install.sh

ENV PATH="/usr/bin/cmake/bin:${PATH}"

RUN apt-get update && \
        apt-get install -y \
        clang \
        clang-tools \
        clang-format \
        clang-tidy \
        git-core \
        python \
        python-pip \
        python3 \
        python3-pip

COPY requirements.txt .
RUN pip install -r requirements.txt


