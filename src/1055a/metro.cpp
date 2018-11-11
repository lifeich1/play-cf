//-[
#include "type.h"
//-]


namespace licf {
namespace metro_1055a {
    // placeholder
}
}

using namespace licf::metro_1055a;

int metro_1055a(const _in_t & in_, _out_t & out_)
{
    int n = in_.n;
    int s = in_.s;
    const int *a = in_.a;
    const int *b = in_.b;
    int *u = out_.u;
    int *lis = out_.lis;

    u[0] = 1;
    lis[0] = 0;
    int q = 1;
    int p = 0;
    int la = -1;
    int rb = n;
    while (p < q && u[s - 1] == 0)
    {
        int x = lis[p++];
        if (a[x])
        {
            for (int i = x + 1; i < rb; ++i)
                if (a[i] == 1 && u[i] == 0)
                {
                    u[i] = 1;
                    lis[q++] = i;
                }
            rb = x;
        }
        if (b[x])
        {
            for (int i = x - 1; i > la; --i)
                if (b[i] == 1 && u[i] == 0)
                {
                    u[i] = 1;
                    lis[q++] = i;
                }
            la = x;
        }
    }
    out_.flag = u[s - 1] == 1;
    return 0;
}

