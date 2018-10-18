//-[
#include "type.h"
//-]

int heaters_1066b(const _1066b_heaters_in_t & in_, _1066b_heaters_out_t & out_)
{
    int u = 0;
    int n = in_.n;
    int r = in_.r;
    const int *a = in_.a;
    int &res = out_.res;
    res = 0;
    int *near = out_.near;
    for (int i = 0, p = -r - 1; i < n; ++i)
    {
        if (a[i]) p = i;
        near[i] = p;
    }
    while (u < n)
    {
        int i;
        if (u + r - 1 < n) i = near[u + r - 1];
        else i = near[n - 1];
        if (i > u - r)
        {
            u = i + r;
            ++ res;
        }
        else
        {
            res = -1;
            return 0;
        }
    }
    return 0;
}
