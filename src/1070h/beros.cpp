//-[
#include "type.h"
#include <cstdio>
//-]

#include <cstring>
#include <algorithm>

namespace licf {
namespace beros_2018ICPC_NEERC_H {
    uint64 numstr(const char *s, int l, int r)
    {
        uint64 res = 0;
        for (int i = l; i <= r; ++i)
        {
            res <<= 8;
            res += s[i];
        }
        return res;
    }

    void insert(StoreMap & m, uint64 key, int pos)
    {
        auto it = m.find(key);
        if (it == m.end()) 
        {
            m[key] = std::make_pair(1, pos);
        }
        else
        {
            if (it->second.second != pos)
            {
                ++ it->second.first;
                it->second.second = pos;
            }
        }
    }
}
}

using namespace licf::beros_2018ICPC_NEERC_H;

int beros_2018ICPC_NEERC_H(const _2018ICPC_NEERC_H_beros_in_t & in_, _2018ICPC_NEERC_H_beros_out_t & out_)
{
    int n = in_.n;
    for (int i = 0; i < n; ++i)
    {
        int len = strlen(in_.s[i]);
        for (int l = 0; l < len; ++l)
            for (int r = l; r < len; ++r)
                insert(out_.store[r - l], numstr(in_.s[i], l, r), i);
    }
    char *q = out_.q;
    while (in_.getq(q))
    {
        int len = strlen(q);
        uint64 key = numstr(q, 0, len - 1);
        auto it = out_.store[len - 1].find(key);
        if (it == out_.store[len - 1].end())
        {
            in_.putres(0, NULL);
        }
        else
        {
            auto p = out_.store[len - 1][key];
            in_.putres(p.first, in_.s[p.second]);
        }
    }
    return 0;
}

