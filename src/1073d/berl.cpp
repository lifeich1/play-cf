//-[
#include "type.h"
#include <cstdio>
//-]


namespace licf {
namespace berl_1073d {
    void insert(LL *a, int n, int x, LL v)
    {
        while (x <= n)
        {
            a[x] += v;
            x += x & (-x);
        }
    }

    LL sumUp(LL *a, int n, int x)
    {
        LL ret = 0;
        while (x > 0)
        {
            ret += a[x];
            x -= x & (-x);
        }
        return ret;
    }

    int lowerBound(LL *a, int n, LL v)
    {
        int r = 0;
        int i = 0;
        for (; (1 << (i + 1)) <= n; ++i);
        for (; i >= 0; --i)
            if (r + (1 << i) <= n && a[r + (1 << i)] <= v)
            {
                r += (1 << i);
                v -= a[r];
            }
        return r;
    }
}
}

using namespace licf::berl_1073d;

int berl_1073d(const _in_t & in_, _out_t & out_)
{
    int n = in_.n;
    LL T = in_.T;
    LL *s = out_.s;
    LL *c = out_.c;
    LL &res = out_.res;
    const int *a = in_.a;

    LL sum = 0;
    int cnt = n;
    for (int i = 0; i < n; ++i)
    {
        sum += a[i];
        insert(s, n, i + 1, a[i]);
        insert(c, n, i + 1, 1);
    }

    while (sum > 0)
    {
        res += (T / sum) * cnt;
        T %= sum;
        while (T < sum)
        {
            int x = lowerBound(s, n, T);
            sum -= a[x];
            cnt --;
            insert(s, n, x + 1, -a[x]);
            insert(c, n, x + 1, -1);
        }
    }
    return 0;
}

