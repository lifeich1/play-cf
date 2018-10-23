//-[
#include "type.h"
#include <cstdio>
//-]

#include <algorithm>

namespace licf {
namespace minipath_1072d {
    tour_node:: tour_node(int x_, int y_)
        : x(x_), y(y_), _k(NULL) 
    {
    }

    int tour_node:: k() const 
    {
        return (_k != NULL) ? *_k : 0;
    }

    void tour_node:: setkp(int *k) 
    {
        _k = k;
    }

    void visit_(int x, int y, int k, int & u, int step
            , int & f, int & cnt, tour_node * lis)
    {
        if (k < 0) return ;
        if (f < k) f = k;
        if (u != step)
        {
            u = step;
            lis[cnt].x = x;
            lis[cnt].y = y;
            lis[cnt++].setkp(&f);
        }
    }
}
}

using namespace licf::minipath_1072d;

int minipath_1072d(const _1072d_minipath_in_t & in_, _1072d_minipath_out_t & out_)
{
    int n = in_.n;
    int p = 1, q = 0;
    tour_node * a = out_.lis[0];
    tour_node * b = out_.lis[1];
    const char (& wd)[2010][2010] = in_.wd;
    char (& res)[4000] = out_.res;
    int (& f)[2010][2010] = out_.f;
    int (& u)[2010][2010] = out_.u;

    for (int i = 0; i < n; ++i)
    {
        std::fill(f[i], f[i] + n, 0);
        std::fill(u[i], u[i] + n, 0);
    }

    if (in_.K > 0 && wd[0][0] != 'a')
    {
        f[0][0] = in_.K - 1;
        res[0] = 'a';
    }
    else
    {
        f[0][0] = in_.K;
        res[0] = wd[0][0];
    }
    a[0].setkp(&f[0][0]);
    //-[
    printf("%d %d\n", f[0][0], in_.K);
    //-]
    for (int step = 1; step < n + n - 1; ++step)
    {
        q = 0;
        // get the next char
        char nx = 'z';
        for (int i = 0; i < p && nx > 'a'; ++i)
        {
            if (a[i].k() > 0)
            {
                nx = 'a';
                break;
            }
            if (a[i].x < n - 1)
                nx = std::min(nx, wd[a[i].x + 1][a[i].y]);
            if (a[i].y < n - 1)
                nx = std::min(nx, wd[a[i].x][a[i].y + 1]);
        }
        // output
        res[step] = nx;
        // filter
        for (int i = 0, x, y; i < p; ++i)
        {
            if (a[i].x < n - 1)
            {
                x = a[i].x + 1;
                y = a[i].y;
                visit_(x, y, a[i].k() - (wd[x][y] != nx)
                        , u[x][y], step, f[x][y], q, b);
            }
            if (a[i].y < n - 1)
            {
                x = a[i].x;
                y = a[i].y + 1;
                visit_(x, y, a[i].k() - (wd[x][y] != nx)
                        , u[x][y], step, f[x][y], q, b);
            }
        }
        std::swap(a, b);
        p = q;
        //-[
        printf("=== u:\n");
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
                printf("%d ", u[i][j]);
            printf("\n");
        }
        printf("=== f:\n");
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
                printf("%d ", f[i][j]);
            printf("\n");
        }
        //-]
    }
    return 0;
}

