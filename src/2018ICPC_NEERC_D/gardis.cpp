//-[
#include "type.h"
//-]

#include <algorithm>

namespace licf {
namespace gardis_2018ICPC_NEERC_D {
    // placeholder
}
}

using namespace licf::gardis_2018ICPC_NEERC_D;

int gardis_2018ICPC_NEERC_D(const _2018ICPC_NEERC_D_gardis_in_t & in_, _2018ICPC_NEERC_D_gardis_out_t & out_)
{
    int n = in_.n;
    long long k = in_.k;
    long long yu = 0;
    long long &res = out_.res;
    res = 0;
    for (int i = 0; i < n; ++i)
    {
        long long r = in_.a[i];
        if (yu > 0)
        {
            ++ res;
            if (yu + r <= k)
            {
                yu = 0;
                continue;
            }
            else 
            {
                r -= k - yu;
            }
        }
        yu = r % k;
        res += r / k;
    }
    res += yu > 0;
    return 0;
}

