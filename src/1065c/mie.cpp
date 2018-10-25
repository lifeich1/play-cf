//-[
#include "type.h"
#include <cstdio>
//-]

#include <algorithm>

namespace licf {
namespace mie_1065c {
    // placeholder
}
}

using namespace licf::mie_1065c;

int mie_1065c(const _in_t & in_, _out_t & out_)
{
    int n = in_.n;
    int K = in_.k;
    int &res = out_.res;
    int *a = out_.a;
    LL *s = out_.s;

    for (int i = 0; i < n; ++i) a[i] = in_.a[i];
    std::sort(a, a + n);
    s[a[n - 1] + 1] = 0;
    for (int h = a[n - 1], i = n - 1; h > 0; --h)
    {
        while (i > 0 && a[i - 1] == h) -- i;
        s[h] = s[h + 1] - i + n;
    }
    for (int h = a[n - 1]; h > a[0]; )
    {
        int nx;
        for (nx = h; s[nx] - s[h + 1] <= K; -- nx);
        res ++;
        h = nx;
    }
    return 0;
}

