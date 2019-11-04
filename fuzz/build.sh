#! /bin/bash

set -e

bin_instr="$1-instr"
bin_standalone="$1-standalone"
c_file="$1.c"

# build(output, flags, lib-folder, source-files)
build () {
    clang \
        $2 \
        -I../libtransmission \
        $4 -o $1 \
        -L./$3/libtransmission -l:libtransmission.a \
        -lz -lssl -lcrypto -lcurl -levent -lminiupnpc -lm -lc -lpthread -lc++abi \
        $3/third-party/natpmp/lib/libnatpmp.a $3/third-party/dht/lib/libdht.a $3/third-party/utp/lib/libutp.a $3/third-party/b64/lib/libb64.a
}

build $bin_instr "-g -fsanitize=address,fuzzer" "build-instr" "$c_file"
build $bin_standalone "-g" "build" "$c_file standalone.c"
