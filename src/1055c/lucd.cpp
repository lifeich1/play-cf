//-[
#include "type.h"
#include <cstdio>
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

    int interval(int x0, int x1, int n0, int n1)
    {
        int l = std::max(x0, x1);
        int r = std::min(x0 + n0, x1 + n1);
        return std::max(r - l, 0);
    }
}
}

using namespace licf::lucd_1055c;

int lucd_1055c(const _in_t & in_, _out_t & out_)
{
    int t = gcd(in_.ta, in_.tb);
    int na = in_.ra - in_.la + 1;
    int nb = in_.rb - in_.lb + 1;
    int a = in_.la % t;
    int b = in_.lb % t;
    int & res = out_.res;
    res = 0;
    res = std::max(res, interval(a, b, na, nb));
    res = std::max(res, interval(a + t, b, na, nb));
    res = std::max(res, interval(a, b + t, na, nb));
    return 0;
}

