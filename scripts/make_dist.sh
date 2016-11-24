#!/usr/bin/env sh

BUILD_TYPE=$1
METHOD=$2
OS=$(uname -s)
ARCH=$(uname -m)
VERSION=$(git describe --tags)
ARCHIVER="tar -cvf"

if [ $BUILD_TYPE != "shared" ] && [ $BUILD_TYPE != "static"  ]
then
	echo "only shared and static builds supported, given: ${BUILD_TYPE}"
	exit 1
fi

if [ -z "${CC}" ]
then
	CC=gcc # default compiler is gcc
fi

DIST="libupnp_${ARCH}_${VERSION}_${CC}_${BUILD_TYPE}.tar.gz"

if [ "${METHOD}" == "getname" ]
then
    echo $DIST
    exit 0
fi

mkdir dist

ARCHIVER="${ARCHIVER} dist/${DIST}"

if [ $BUILD_TYPE == "shared" ]
then
	FILES=$(find ./prebuild/${OS} -name "*.dll" -o -name "*.dll.a" -o -name "*.so" -o -name "*.dylib")
else
	FILES=$(rm -f ./prebuild/${OS}/*.dll.a && find ./prebuild/${OS} -name "*.a")
fi

`${ARCHIVER} ${FILES}`

