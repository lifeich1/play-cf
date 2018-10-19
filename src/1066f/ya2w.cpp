//-[
#include "type.h"
#include <cstdio>
//-]

#include <algorithm>

namespace licf {
namespace ya2w_1066f {
    bool operator< (const point & lhs, const point & rhs)
    {
        return lhs.u() < rhs.u() || (lhs.u() == rhs.u() 
                && lhs.v() < rhs.v());
    }
    _int64 dist(const point & lhs, const point & rhs)
    {
        return (lhs.x > rhs.x ? lhs.x - rhs.x : rhs.x - lhs.x)
            + (lhs.y > rhs.y ? lhs.y - rhs.y : rhs.y - lhs.y);
    }
}
}

using namespace licf::ya2w_1066f;

static void prepare_points(int n, const int *x, const int *y, point * p)
{
    for (int i = 0; i < n; ++i)
    {
        p[i].x = x[i];
        p[i].y = y[i];
    }
    std::sort(p, p + n);
}

int ya2w_1066f(const _1066f_ya2w_in_t & in_, _1066f_ya2w_out_t & out_)
{
    int n = in_.n;
    prepare_points(n, in_.x, in_.y, out_.p);
    _int64 f[2];
    f[0] = f[1] = 0;
    point lo(0, 0), hi(0, 0);
    point *ps = out_.p;
    for (int lf = 0, rt = 0; lf < n; lf = rt)
    {
        while (rt < n && ps[lf].u() == ps[rt].u()) ++ rt;

        _int64 tmp, l, f1[2];
        l = dist(ps[lf], ps[rt - 1]);

        f1[0] = f[0] + dist(lo, ps[rt - 1]) + l;
        f1[1] = f[1] + dist(hi, ps[lf]) + l;
        tmp = f[1] + dist(hi, ps[rt - 1]) + l;
        if (tmp < f1[0]) f1[0] = tmp;
        tmp = f[0] + dist(lo, ps[lf]) + l;
        if (tmp < f1[1]) f1[1] = tmp;

        lo = ps[lf];
        hi = ps[rt - 1];
        f[0] = f1[0];
        f[1] = f1[1];
    }
    out_.res = std::min(f[0], f[1]);
    return 0;
}
