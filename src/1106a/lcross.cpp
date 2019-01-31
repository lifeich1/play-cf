//-[
#include "type.h"
//-]


namespace licf {
namespace lcross_1106a {
    // placeholder
}
}

using namespace licf::lcross_1106a;

int lcross_1106a(const _in_t & in_, _out_t & out_)
{
    int n = in_.n;
    const char (&a)[512][512] = in_.a;
    int &ans = out_.ans;

    for (int i = 1; i < n - 1; ++i)
        for (int j = 1; j < n - 1; ++j)
        {
            bool fl = a[i][j] == 'X'
                && a[i - 1][j - 1] == 'X'
                && a[i - 1][j + 1] == 'X'
                && a[i + 1][j - 1] == 'X'
                && a[i + 1][j + 1] == 'X';
            if (fl) ans ++;
        }
    return 0;
}


