//-[
#include "type.h"
//-]


namespace licf {
namespace emm_1064b {
    // placeholder
}
}

using namespace licf::emm_1064b;

int emm_1064b(const _in_t & in_, _out_t & out_)
{
    int n;
    while (in_.read(&n))
    {
        LL res = 1;
        for (; n > 0; n >>= 1)
        {
            if (n & 1)
            {
                res <<= 1ll;
            }
        }
        in_.put(res);
    }
    return 0;
}

