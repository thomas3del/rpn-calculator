FROM ubuntu:22.04

RUN apt-get update && \
    apt-get install -y cmake g++ git && \
    rm -rf /var/lib/apt/lists/*

WORKDIR /app
COPY . .

RUN rm -rf build && \
    cmake -B build -DCMAKE_BUILD_TYPE=Release && \
    cmake --build build --target rpn_calculator

CMD ["./build/rpn_calculator"]
