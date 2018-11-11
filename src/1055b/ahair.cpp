//-[
#include "type.h"
#include <cstdio>
//-]


namespace licf {
namespace ahair_1055b {
    // placeholder
}
}

using namespace licf::ahair_1055b;

int ahair_1055b(const _in_t & in_, _out_t & out_)
{
    int n = in_.n;
    int m = in_.m;
    int l = in_.l;
    int *a = out_.a;

    int ans = 0;
    for (int i = 0; i < n; ++i)
        if (a[i] > l && (i == 0 || a[i - 1] <= l))
            ans ++;

    int p, d;
    while (m-- > 0)
    {
        int op = in_.get(&p, &d);
        if (op == 0)
        {
            in_.put(ans);
        }
        else
        {
            p--;
            if (a[p] + d > l && a[p] <= l)
            {
                if ((p == 0 || a[p - 1] <= l) &&
                        (p == n - 1 || a[p + 1] <= l))
                    ans ++;
                else if (p > 0 && p < n - 1 && a[p - 1] > l
                        && a[p + 1] > l)
                    ans --;
            }
            if (a[p] <= l) a[p] += d;
        }
    }
    return 0;
}

