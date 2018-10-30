//-[
#include "type.h"
#include <cstdio>

#define debug_pf(f, c, i, j) do { \
    printf("%d %d\n", f[i][j], c[i][j]); \
} while (0);
//-]

#ifndef debug_pf 
#define debug_pf(f, c, i, j)
#endif

#include <algorithm>

namespace licf {
namespace segs_1073e {
    const int modn = 998244353;

    void reset_f(reff_t f)
    {
        for (int i = 0; i < 20; ++i)
            std::fill(f[i], f[i] + 1024, 0);
    }

    void subcalc(LL L, _out_t & out_, int K)
    {
        reff_t f = out_.f;
        reff_t c = out_.c;
        reff_t fu = out_.fu;
        reff_t cu = out_.cu;
        int * dig = out_.dig;
        int * d10 = out_.d10;
        int & res = out_.res;

        reset_f(f);
        reset_f(c);

        for (int i = 0; i <= (L % 10); ++i)
            f[0][(1 << i)] = i, c[0][(1 << i)] = 1;

        res = 0;
        int la = 45;
        L /= 10;
        int i;
        for (i = 1; L > 0; L /= 10, ++i)
        {
            res = (res + la) % modn;
            int u = L % 10;
            for (int k = (u == L ? 1 : 0); k < u; ++k)
                for (int j = 1; j < 1024; ++j)
                {
                    int t = j | (1 << k);
                    f[i][t] = (f[i][t] + fu[i - 1][j]) % modn;
                    int tmp = ((LL)k * d10[i]) % modn;
                    tmp = ((LL)tmp * cu[i - 1][j]) % modn;
                    f[i][t] = (f[i][t] + tmp) % modn;
                    c[i][t] = (c[i][t] + cu[i - 1][j]) % modn;
                }
            for (int j = 1; j < 1024; ++j)
            {
                int t = j | (1 << u);
                f[i][t] = (f[i][t] + f[i - 1][j]) % modn;
                int tmp = ((LL)u * c[i - 1][j]) % modn;
                tmp = ((LL)tmp * d10[i]) % modn;
                f[i][t] = (f[i][t] + tmp) % modn;
                c[i][t] = (c[i][t] + c[i - 1][j]) % modn;
            }

            la = 0;
            for (int k = 1; k < 10; ++k)
            {
                for (int j = 1; j < 1024; ++j)
                {
                    int t = j | (1 << k);
                    if (dig[t] <= K)
                    {
                        int tmp = ((LL)k * d10[i]) % modn;
                        tmp = ((LL)tmp * cu[i - 1][j]) % modn;
                        la = (la + fu[i - 1][j]) % modn;
                        la = (la + tmp) % modn;
                    }
                }
            }
        }

        -- i;
        for (int j = 1; j < 1024; ++j)
            if (dig[j] <= K) res = (res + f[i][j]) % modn;
    }
}
}

using namespace licf::segs_1073e;

int segs_1073e(const _in_t & in_, _out_t & out_)
{
    LL L = in_.l;
    LL R = in_.r;
    int K = in_.k;

    reff_t fu = out_.fu;
    reff_t cu = out_.cu;
    int * dig = out_.dig;
    int * d10 = out_.d10;
    int & res = out_.res;

    for (int i = 0; i < 1024; ++i)
    {
        dig[i] = 0;
        for (int t = i; t > 0; t >>= 1) dig[i] += t & 1;
    }

    d10[0] = 1;
    for (int i = 1; i <= 18; ++i) d10[i] = ((LL)d10[i - 1] * 10ll) % modn;

    reset_f(fu);
    reset_f(cu);

    for (int i = 0; i < 10; ++i) fu[0][(1 << i)] = i, cu[0][(1 << i)] = 1;
    for (int i = 1; i < 18; ++i) 
    {
        for (int j = 1; j < 1024; ++j)
            for (int k = 0; k < 10; ++k)
            {
                int t = (1 << k) | j;
                cu[i][t] = (cu[i][t] + cu[i - 1][j]) % modn;
                fu[i][t] = ((LL)fu[i][t] + fu[i - 1][j]) % modn;
                int tmp = ((LL)d10[i] * cu[i - 1][j]) % modn;
                tmp = ((LL)tmp * k) % modn;
                fu[i][t] = (fu[i][t] + tmp) % modn;
            }
    }
    
    subcalc(L - 1, out_, K);
    int lres = res;
    subcalc(R, out_, K);
    res = ((LL)res - lres + modn) % modn;
    return 0;
}

