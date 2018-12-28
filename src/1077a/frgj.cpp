//-[
#include "type.h"
#include <cstdio>
//-]


namespace licf {
namespace frgj_1077a {
    // placeholder
}
}

using namespace licf::frgj_1077a;

int frgj_1077a(const _in_t & in_, _out_t & out_)
{
    int a, b, k;
    while (!in_.get(&a, &b, &k))
    {
        long long s = a - b;
        s *= k >> 1;
        if (k & 1) s += a;
        in_.put(s);
    }
    return 0;
}


