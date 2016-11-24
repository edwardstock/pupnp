#!/usr/bin/env bash

DIST="libupnp_$(uname -p)_$(git describe --tags).tar.tz"

ARG=$1

if [ $ARG == "getname" ]
then
    echo $DIST
    exit
fi

tar -zcvf $NAME