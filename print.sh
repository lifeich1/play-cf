#!/bin/bash

if [ -z $1 ]; then
    echo "Need argument"
    exit 1
fi
if [ ! -d ./src/$1 ]; then
    echo "Invalid argument"
    exit 1
fi

DIR=./src/$1

cat $DIR/type.h
find $DIR -name "*.cpp" -exec sed '/^\/\/-\[/,/^\/\/-\]/d' {} \;
sed "1d" $DIR/_io.cc
