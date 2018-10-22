//-[
#include "type.h"
#include <cstdio>
//-]


namespace licf {
namespace curiosity_1072b {
    // placeholder
}
}

using namespace licf::curiosity_1072b;

int curiosity_1072b(const _1072b_curiosity_in_t & in_, _1072b_curiosity_out_t & out_)
{
    int n = in_.n;
    const int *a = in_.a;
    const int *b = in_.b;
    out_.flag = false;
    for (int i = 0; i < n; ++i)
        if ((a[i] & b[i]) != b[i]) return 0;
    int *res = out_.res;
    for (int st = 0; st < 4; ++st)
    {
        if ((st & b[0]) != b[0]) continue;
        res[0] = st;
        //-[
        printf("%d ", st);
        //-]
        for (int i = 1; i <= n; ++i)
        {
            res[i] = (res[i - 1] ^ (~b[i - 1])) & a[i - 1];
            //-[
            printf("%d(%d %d %d) ", res[i], res[i - 1], b[i - 1], a[i - 1]);
            //-]
            if ((res[i] | res[i - 1]) != a[i - 1]) break;
            if ((res[i] & res[i - 1]) != b[i - 1]) break;
            if (i == n)
            {
                out_.flag = true;
                return 0;
            }
        }
        //-[
        printf("\n");
        //-]
    }
    return 0;
}

