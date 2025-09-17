FROM ubuntu:22.04


RUN apt-get update && apt-get install -y \
    build-essential cmake git wget && \
    rm -rf /var/lib/apt/lists/*

WORKDIR /app

COPY . /app

RUN git clone https://github.com/google/googletest.git -b v1.17.0

RUN mkdir build
WORKDIR /app/build

RUN cmake .. && cmake --build .
