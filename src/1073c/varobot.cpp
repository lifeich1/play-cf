//-[
#include "type.h"
#include <cstdio>
//-]


namespace licf {
namespace varobot_1073c {
    bool isReachable(int n, int x0, int y0, int x1, int y1)
    {
        int x = x1 - x0;
        int y = y1 - y0;
        if (x < 0) x = -x;
        if (y < 0) y = -y;
        return (n - x >= y) && (((x ^ y ^ n) & 1) == 0);
    }
}
}

using namespace licf::varobot_1073c;

static bool check(const _in_t & in_, _out_t & out_, int w)
{
    const int & n = in_.n;
    const int & ex = in_.x;
    const int & ey = in_.y;
    int (&d)[200100][2] = out_.d;
    for (int i = 0; i <= n - w; ++ i)
    {
        int tx = d[n][0] - d[i + w][0];
        int ty = d[n][1] - d[i + w][1];
        if (isReachable(w, d[i][0], d[i][1],
                    ex - tx, ey - ty))
            return true;
    }
    return false;
}

int varobot_1073c(const _in_t & in_, _out_t & out_)
{
    int n = in_.n;
    int ex = in_.x;
    int ey = in_.y;
    int & res = out_.res;
    res = -1;
    if (!isReachable(n, 0, 0, ex, ey)) return 0;

    const char *s = in_.s;
    int (&d)[200100][2] = out_.d;

    d[0][0] = d[0][1] = 0;
    for (int i = 0; i < n; ++i)
    {
        switch (s[i])
        {
            case 'U':
                d[i + 1][0] = d[i][0];
                d[i + 1][1] = d[i][1] + 1;
                break;
            case 'D':
                d[i + 1][0] = d[i][0];
                d[i + 1][1] = d[i][1] - 1;
                break;
            case 'L':
                d[i + 1][0] = d[i][0] - 1;
                d[i + 1][1] = d[i][1];
                break;
            case 'R':
                d[i + 1][0] = d[i][0] + 1;
                d[i + 1][1] = d[i][1];
                break;
        }
    }

    if (d[n][0] == ex && d[n][1] == ey)
    {
        res = 0;
        return 0;
    }

    int l = 1;
    int r = n;
    while (l < r)
    {
        int mid = (l + r) >> 1;
        if (check(in_, out_, mid))
            r = mid;
        else 
            l = mid + 1;
    }
    res = l;
    return 0;
}

