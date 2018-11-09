//-[
#include "type.h"
//-]


namespace licf {
namespace ch2pa_1073f {
    edge::edge(int y, edge * nx): y(y), nx(nx) {}

    void addEdge(edge **head, int y)
    {
        edge *e = new edge(y, *head);
        *head = e;
    }
}
}

using namespace licf::ch2pa_1073f;

int ch2pa_1073f(const _in_t & in_, _out_t & out_)
{
    int n = in_.n;
    const int *eg = in_.e;
    int *degree = out_.degree;
    edge **eh = out_.eh;
    int *goodSt = out_.goodSt;
    int *goodVal = out_.goodVal;
    int *goodTag = out_.goodTag;
    int *ingood = out_.ingood;

    // calc degree
    for (int i = 0; i < n - 1; ++i)
    {
        degree[eg[i][0]] ++;
        degree[eg[i][1]] ++;
    }

    // build graph (add edges)
    for (int i = 0; i < n - 1; ++i)
    {
        int a = eg[i][0], b = eg[i][1];
        addEdge(&eh[a], b);
        addEdge(&eh[b], a);
    }

    // travel good path
    for (int g = 0; g < n; ++g)
        if (degree[g] == 1)
        {
            int la = -1;
            int v = 0;
            int x = g;
            while (degree[x] < 3)
            {
                edge *e = eg[x];
                while (e->y == la) e = e->nx;
                v ++;
                la = x;
                x = e->y;
                ingood[la] = true;
            }
            ++ goodSt[x];
            // insert good path value & tag
            if (v > goodVal[x][0])
            {
                goodVal[x][1] = goodVal[x][0];
                goodTag[x][1] = goodTag[x][0];
                goodVal[x][0] = v;
                goodTag[x][0] = g;
            }
            else if (v > goodVal[x][1])
            {
                goodVal[x][1] = v;
                goodTag[x][1] = g;
            }
        }

    // unlink good path
    for (int i = 0; i < n; ++i)
        if (!ingood[i])
        {
            edge *e = eh[i];
            edge **pa = &eh[i];
            while (e != NULL)
            {
                if (ingood[e->y])
                {
                    *pa = e->nx;
                }
                else
                {
                    pa = &e->nx;
                }
                e = e->nx;
            }
        }

    // search diameter
    // grab diameter center
    // greedy travel
    return 0;
}

