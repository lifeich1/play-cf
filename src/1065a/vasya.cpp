//-[
#include "type.h"
//-]


namespace licf {
namespace vasya_1065a {
    // placeholder
}
}

using namespace licf::vasya_1065a;

int vasya_1065a(const _in_t & in_, _out_t & out_)
{
    int s, a ,b, c;
    while (in_.read(&s, &a, &b, &c))
    {
        LL res = s / c;
        res += (res / a) * (LL)b;
        in_.put(res);
    }
    return 0;
}

