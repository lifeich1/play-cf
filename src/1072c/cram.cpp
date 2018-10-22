//-[
#include "type.h"
//-]

#include <cmath>

namespace licf {
namespace cram_1072c {
    // placeholder
}
}

using namespace licf::cram_1072c;

int cram_1072c(const _1072c_cram_in_t & in_, _1072c_cram_out_t & out_)
{
    int a = in_.a;
    int b = in_.b;
    LL t = (a + b) * 2ll;
    int n = (int)(sqrt(t));
    if ((LL)n * (n + 1) > t) -- n;
    out_.n = n;
    int &p = out_.p;
    int &q = out_.q;
    for (int i = n; i > 0; --i)
        if (a >= i)
        {
            p ++;
            a -= i;
            out_.flag[i] = true;
        }
        else
        {
            q ++;
            out_.flag[i] = false;
        }
    return 0;
}

