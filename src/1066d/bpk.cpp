//-[
#include "type.h"
//-]

static bool _check(int n, int m, int k, const int *a)
{
    int l = 0;
    for (int i = 0, s = 0; i < n; ++i)
    {
        if (a[i] > k) return false;
        if (a[i] + s > k)
        {
            s = 0;
            if (++l >= m) return false;
        }
        s += a[i];
    }
    return true;
}

int bpk_1066d(const _1066d_bpk_in_t & in_, _1066d_bpk_out_t & out_)
{
    int n = in_.n;
    int m = in_.m;
    int k = in_.k;
    const int *a = in_.a;
    int l, r;
    for (l = 0, r = n; l < r; )
    {
        int t = (l + r) >> 1;
        if (_check(n - t, m, k, a + t))
            r = t;
        else
            l = t + 1;
    }
    out_.res = n - l;
    return 0;
}
