//-[
#include "type.h"
//-]


namespace licf {
namespace plate_1072a {
    // placeholder
}
}

using namespace licf::plate_1072a;

int plate_1072a(const _1072a_plate_in_t & in_, _1072a_plate_out_t & out_)
{
    int n = in_.n;
    int m = in_.m;
    int k = in_.k;
    if (n > m) {
        n ^= m;
        m ^= n;
        n ^= m;
    }
    int &res = out_.res;
    for (int i = 0; i < k; ++i)
    {
        int w = n - 4 * i;
        int h = m - 4 * i;
        if (w > 1)
        {
            res += (w + h - 2) * 2;
        }
        else
        {
            res += h;
        }
    }
    return 0;
}

