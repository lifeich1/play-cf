//-[
#include "type.h"
//-]


namespace licf {
namespace elest_1054a {
    int abs(int x)
    {
        return x < 0 ? -x : x;
    }
}
}

using namespace licf::elest_1054a;

int elest_1054a(const _in_t & in_, _out_t & out_)
{
    int u0 = abs(in_.x - in_.y) * in_.t1;
    int u1 = (abs(in_.x - in_.z) + abs(in_.x - in_.y)) * in_.t2
        + in_.t3 * 3;
    out_.flag = u0 >= u1;
    return 0;
}

