//-[
#include "type.h"
//-]

#include <algorithm>

namespace licf {
namespace lucd_1055c {
    int gcd(int a, int b)
    {
        while (b != 0)
        {
            int c = a % b;
            a = b;
            b = c;
        }
        return a;
    }
}
}

using namespace licf::lucd_1055c;

int lucd_1055c(const _in_t & in_, _out_t & out_)
{
    int t = gcd(in_.ta, in_.tb);
    int m = std::min(in_.ra - in_.la, in_.rb - in_.lb) + 1;
    int e = std::abs(in_.la - in_.lb) % t;
    if (t - e < e) e = t - e;
    out_.res = std::max(m - e, 0);
    return 0;
}

