#!/bin/bash

export CFHOME=`pwd -P`
export CFCODE=""
NEW=$CFHOME/new.sh
PRINT="$CFHOME/print.sh"

cfworkdir() {
    echo "$CFHOME/src/$CFCODE"
}

into() {
    if [ -d `cfworkdir` ]; then
        cd `cfworkdir`
    else
        echo "problem does not set or initialized."
    fi
}

uptop() {
    cd $CFHOME
}

atproblem() {
    export CFCODE=$1
}

newproblem() {
    tmp=$OLDPWD
    olddir=`pwd`
    uptop
    $NEW $1 $2 && atproblem $1
    cd $olddir
    export OLDPWD=$tmp
}


editall() {
    dir=`cfworkdir`
    vim $dir/_io.cc $dir/type.h $dir/*.cpp
}

editmain() {
    vim `cfworkdir`/*.cpp
}

editio() {
    vim `cfworkdir`/_io.cc
}

edittype() {
    vim `cfworkdir`/type.h
}

runtest() {
    if [ -d `cfworkdir` ]; then
        test -z $TMPDIR && TMPDIR='.'
        echo '/*=== compiling ===*/'
        g++ -I `cfworkdir` \
            `cfworkdir`/*.cc \
            `cfworkdir`/*.cpp \
            -Wall \
            -std=c++11 \
            -o $TMPDIR/a.out
        echo '/*=== running ===*/'
        $TMPDIR/a.out
    else
        echo "problem does not set or initialized."
    fi
}

pcode() {
    tmp=$OLDPWD
    olddir=`pwd`
    uptop
    $PRINT $CFCODE
    cd $olddir
    export OLDPWD=$tmp
}

cpcode() {
    pcode | pbcopy && echo 'copied.'
}
