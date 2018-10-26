//-[
#include "type.h"
//-]


namespace licf {
namespace vabook_1073b {
    // placeholder
}
}

using namespace licf::vabook_1073b;

int vabook_1073b(const _in_t & in_, _out_t & out_)
{
    int n = in_.n;
    const int *a = in_.a;
    const int *b = in_.b;
    int * pos = out_.pos;
    int * res = out_.res;

    int cnt = 0;
    for (int i = 0; i < n; ++i) pos[a[i]] = i;
    for (int i = 0; i < n; ++i)
    {
        if (pos[b[i]] >= cnt)
        {
            res[i] = pos[b[i]] - cnt + 1;
            cnt = pos[b[i]] + 1;
        }
        else
            res[i] = 0;
    }
    return 0;
}

