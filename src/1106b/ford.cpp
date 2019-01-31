//-[
#include "type.h"
//-]
#include <algorithm>

namespace licf {
namespace ford_1106b {
    const int *abase;

    bool cmp_base(const int &lhs, const int &rhs)
    {
        return abase[lhs] < abase[rhs] ||
            (abase[lhs] == abase[rhs] && lhs < rhs);
    }
}
}

using namespace licf::ford_1106b;

int ford_1106b(const _in_t & in_, _out_t & out_)
{
    abase = in_.c;
    int (&h)[100100] = out_.h;
    int n = in_.n;
    int m = in_.m;

    for (int i = 0; i < n; ++i) out_.a[i] = in_.a[i];
    for (int i = 0; i < n; ++i) h[i] = i;
    for (int i = 0; i < m; ++i) out_.ans[i] = 0;
    std::sort(h, h + n, cmp_base);

    int pt = 0;
    int (&a)[100100] = out_.a;
    for (int i = 0; i < m; ++i)
    {
        LL tmp = 0;
        int k = in_.t[i] - 1;
        int r = in_.d[i];
        if (a[k] < r) r = a[k];
        tmp += r * static_cast<LL>(in_.c[k]);
        a[k] -= r;
        r = in_.d[i] - r;
        while (r > 0 && pt < n)
        {
            k = h[pt];
            int t = std::min(a[k], r);
            tmp += t * static_cast<LL>(in_.c[k]);
            a[k] -= t;
            r -= t;
            if (0 == a[k]) pt++;
        }
        if (r > 0)
        {
            break;
        }
        else
        {
            out_.ans[i] = tmp;
        }
    }
    return 0;
}


