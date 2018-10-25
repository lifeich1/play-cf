#!/bin/bash

export CFHOME=`pwd -P`
if [ -z $CFCODE ]; then
    _OLD_PROG_CF_PS1_=''
fi
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
    if ! [ -z $_OLD_PROG_CF_PS1_ ]; then
        export PS1=$_OLD_PROG_CF_PS1_
        _OLD_PROG_CF_PS1_=''
    fi
    if ! [ -z $1 ]; then
        _OLD_PROG_CF_PS1_=$PS1
        export PS1="[$1] $PS1"
    fi
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
    vim -p $dir/_io.cc $dir/type.h $dir/*.cpp
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
            -o $TMPDIR/a.out || return 1
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
    if [ `uname` = Darwin ]; then
        pbcopy=pbcopy
    else
        pbcopy='xsel -b'
    fi
    pcode | $pbcopy && echo 'copied.'
}
