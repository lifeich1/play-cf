//-[
#include "type.h"
#include <cstdio>
//-]


namespace licf {
namespace vpst_2018ICPC_NEERC_K {
    // placeholder
}
}

using namespace licf::vpst_2018ICPC_NEERC_K;

int vpst_2018ICPC_NEERC_K(const _2018ICPC_NEERC_K_vpst_in_t & in_, _2018ICPC_NEERC_K_vpst_out_t & out_)
{
    int n = in_.n;
    int k = in_.k;
    const int *a = in_.a;
    int sum = 0;
    for (int i = 0; i < n; ++i) sum += a[i];
    out_.flag = false;
    if (sum % k != 0) return 1;
    int line = sum / k;
    //-[
    printf("%d %d\n", sum, line);
    //-]
    for (int p = 0, l = 0; p < k; ++ p)
    {
        int i, t;
        for (i = l, t = 0; i < n && t < line; t += a[i++]);
        //-[
        printf("%d %d\n", i, t);
        //-]
        if (t != line) return 1;
        out_.res[p] = i - l;
        l = i;
    }
    out_.flag = true;
    return 0;
}

