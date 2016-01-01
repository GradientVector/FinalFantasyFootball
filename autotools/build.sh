#!/usr/bin/env sh
mkdir -p build
cd build
if [ -n "$1" ] 
then
    ../configure --prefix=$1
else
    ../configure
fi
make
