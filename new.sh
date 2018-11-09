#!/bin/bash

code=$1
name=$2

if [ -z "$1" -o -z "$2" ]; then
    echo "lack of argument"
    exit 1
fi

dir=./src/$code

tbase="_${code}_${name}"
tmacro="${tbase}_H_INCLUDE"
tin="${tbase}_in_t"
tout="${tbase}_out_t"

tfunc="${name}_${code}"

new_type_h() {
    cat > type.h << END
#ifndef $tmacro
#define $tmacro

struct $tin;
struct $tout;

namespace licf {
namespace $tfunc {
    typedef struct $tin _in_t;
    typedef struct $tout _out_t;
    typedef struct $tout _data_t;

    // placeholder
}
}

struct $tin {
    int __padding;
};

struct $tout {
    const struct $tin * in_;

    // placeholder
};

typedef struct $tin $tin;
typedef struct $tout $tout;

extern int
$tfunc(const $tin &, $tout &);


#endif  // $tmacro
END
}

new_algo_cpp() {
    cat > ${name}.cpp << END
//-[
#include "type.h"
//-]


namespace licf {
namespace $tfunc {
    // placeholder
}
}

using namespace licf::$tfunc;

int $tfunc(const _in_t & in_, _out_t & out_)
{
    // placeholder
    return 0;
}

END
}

new_io_cc() {
    cat > _io.cc << END
#include "type.h"
#include <cstdio>

using namespace std;

$tin in_;
$tout out_ = {&in_};

void _get_input()
{
    // placeholder
}

void _print_output()
{
    // placeholder
}

int main(int argc, char *argv[])
{
    _get_input();
    $tfunc(in_, out_);
    _print_output();
    return 0;
}
END
}

if [ ! -d $dir ]; then
    # new project
    mkdir -p $dir
    cd $dir
    new_type_h
    new_algo_cpp
    new_io_cc
else
    # rename project
    cd $dir
    oname=`ls *.cpp| head -n 1`
    oname=${oname/.cpp/}
    obase="_${code}_${oname}"
    omacro="${obase}_H_INCLUDE"
    oin="${obase}_in_t"
    oout="${obase}_out_t"
    ofunc="${oname}_${code}"

    if [ `uname` = Darwin ]; then
        msedcmd="sed -i '' -e"
    else
        msedcmd='sed -i -e'
    fi

    $msedcmd "s/${obase}/${tbase}/g" type.h
    $msedcmd "s/${ofunc}/${tfunc}/g" type.h
    $msedcmd "s/${obase}/${tbase}/g" _io.cc
    $msedcmd "s/${ofunc}/${tfunc}/g" _io.cc
    $msedcmd "s/${obase}/${tbase}/g" ${oname}.cpp
    $msedcmd "s/${ofunc}/${tfunc}/g" ${oname}.cpp
    mv ${oname}.cpp ${name}.cpp
fi
