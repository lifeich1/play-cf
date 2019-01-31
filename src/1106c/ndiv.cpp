//-[
#include "type.h"
#include <cstdio>
//-]
#include <algorithm>

namespace licf {
namespace ndiv_1106c {
    // placeholder
}
}

using namespace licf::ndiv_1106c;

int ndiv_1106c(const _in_t & in_, _out_t & out_)
{
    int n = in_.n;
    for (int i = 0; i < n; ++i) out_.a[i] = in_.a[i];
    std::sort(out_.a, out_.a + n);
    int m = n >> 1;
    out_.ans = 0;
    for (int i = 0; i < m; ++i)
    {
        int t = out_.a[i] + out_.a[n - i - 1];
        out_.ans += t * t;
    }
    return 0;
}


