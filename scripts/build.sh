#!/usr/bin/env bash

BUILD_TYPE=$1

if [ $BUILD_TYPE == "" ]
then
    echo "Build type is not set! Select shared or static"
    exit 1
fi

if [ -d "build" ]; then
  rm -rf build/*
else
  mkdir -p build
fi

cd build

if [ $BUILD_TYPE == "shared" ]
then
    cmake ../ -DENABLE_STATIC=OFF
    cmake ../ -DENABLE_STATIC=OFF
else
    cmake ../ -DENABLE_STATIC=ON
    cmake ../ -DENABLE_STATIC=ON
fi

make



