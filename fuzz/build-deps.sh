#! /bin/bash

set -e

export CC=clang
export CXX=clang++

# build(directory, flags)
build () {
    mkdir -p $1
    pushd $1

    CFLAGS=$2 CXXFLAGS=$2 cmake ../..

    cd libtransmission
    make

    popd
}

build "build" "-g"
build "build-instr" "-g -fsanitize=address,fuzzer-no-link"
