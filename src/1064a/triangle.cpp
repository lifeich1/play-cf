//-[
#include "type.h"
//-]

#include <algorithm>

namespace licf {
namespace triangle_1064a {
    // placeholder
}
}

using namespace licf::triangle_1064a;

int triangle_1064a(const _in_t & in_, _out_t & out_)
{
    int a = in_.a;
    int b = in_.b;
    int c = in_.c;
    if (b < c) std::swap(b, c);
    if (a < b) std::swap(a, b);
    out_.res = (a < b + c) ? 0 : (a - b - c + 1);
    return 0;
}

