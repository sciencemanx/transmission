FROM fuzz-base

# get libtransmisson dependencies
RUN apt-get update && apt-get install -y \
    libcurl4-openssl-dev libglib2.0-dev libevent-dev libminiupnpc-dev \
    libgtk-3-dev libappindicator3-dev libssl-dev zlib1g-dev

WORKDIR /transmission
COPY ./ .

# build fuzzers
WORKDIR /transmission/fuzz

RUN ./build-deps.sh && \
    ./build.sh json/fuzz_json && \
    ./build.sh bencode/fuzz_bencode && \
    ./build.sh wildmat/fuzz_wildmat && \
    rm -rf build build-instr
