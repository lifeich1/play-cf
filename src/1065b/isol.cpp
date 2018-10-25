//-[
#include "type.h"
//-]

#include <cmath>
#include <algorithm>

namespace licf {
namespace isol_1065b {
    // placeholder
}
}

using namespace licf::isol_1065b;

int isol_1065b(const _in_t & in_, _out_t & out_)
{
    int n = in_.n;
    LL m = in_.m;
    int *res = out_.res;

    res[0] = std::max((LL)n - m * 2, 0ll);
    LL t = static_cast<LL>(std::floor(std::sqrt(m + m)));
    for (; t * (t - 1) < m + m; ++t);
    res[1] = static_cast<int>(n - t);
    return 0;
}

