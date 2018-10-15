#!/bin/bash

code=$1
name=$2

if [ -z "$1$2" ]; then
    echo "lack of argument"
fi

dir=./src/$code

tbase="_${code}_${name}"
tmacro="_${tbase}_H_INCLUDE"
tin="${tbase}_in_t"
tout="${tbase}_out_t"

tfunc="${name}_${code}"

if [ ! -d $dir ]; then
    mkdir -p $dir
    cd $dir
    cat > type.h << END
#ifndef $tmacro
#define $tmacro

typedef $tin struct {
    int __padding;
};

typedef $tout struct {
    int __padding;
};

extern int
$tfunc(const $tin &, $tout &);


#endif  // $tmacro
END
    cat > ${name}.cpp << END

int $func(const $tin & in, $tout & out)
{
    return 0;
}
END
    cat > _io.cc << END
#include "type.h"
#include <cstdio>

using namespace std;

$tin in;
$tout out;

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
    _get_input()
    $tfunc(in, out);
    _print_output();
    return 0;
}
END
