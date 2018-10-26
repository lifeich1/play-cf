//-[
#include "type.h"
//-]

#include <algorithm>

namespace licf {
namespace dsub_1073a {
    // placeholder
}
}

using namespace licf::dsub_1073a;

int dsub_1073a(const _in_t & in_, _out_t & out_)
{
    int n = in_.n;
    const char *s = in_.s;
    int *cnt = out_.cnt;

    for (int st = 0; st < n; ++st)
    {
        int minlen = 1;
        std::fill(cnt, cnt + 26, 0);
        for (int i = st; i < n; ++i)
        {
            minlen = std::max(minlen, (++cnt[s[i] - 'a']) * 2);
            if (i - st + 1 >= minlen)
            {
                out_.flag = true;
                out_.l = st;
                out_.r = i + 1;
                return 0;
            }
        }
    }
    out_.flag = false;
    return 0;
}

