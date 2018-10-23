//-[
#include "type.h"
//-]


namespace licf {
namespace vova_1066a {
    // placeholder
}
}

using namespace licf::vova_1066a;

int vova_1066a(const _in_t & in_, _out_t & out_)
{
    int L, v, l, r;
    while (in_.read(&L, &v, &l, &r))
    {
        in_.put(L / v - r / v + (l - 1) / v);
    }
    return 0;
}

