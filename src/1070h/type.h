#ifndef _2018ICPC_NEERC_H_beros_H_INCLUDE
#define _2018ICPC_NEERC_H_beros_H_INCLUDE

#include <map>
#include <algorithm>

namespace licf {
namespace beros_2018ICPC_NEERC_H {
    typedef unsigned long long uint64;

    uint64 numstr(const char *s, int l, int r);

    typedef std::map<uint64, std::pair<int, int> > StoreMap;

    void insert(StoreMap &, uint64 key, int pos);
}
}

struct _2018ICPC_NEERC_H_beros_in_t {
    int n, q;
    char s[10010][9];
    bool (*getq)(char *);
    void (*putres)(int, const char *);
};

struct _2018ICPC_NEERC_H_beros_out_t {
    char q[9];
    licf::beros_2018ICPC_NEERC_H::StoreMap store[8];
};

typedef struct _2018ICPC_NEERC_H_beros_in_t _2018ICPC_NEERC_H_beros_in_t;
typedef struct _2018ICPC_NEERC_H_beros_out_t _2018ICPC_NEERC_H_beros_out_t;

extern int
beros_2018ICPC_NEERC_H(const _2018ICPC_NEERC_H_beros_in_t &, _2018ICPC_NEERC_H_beros_out_t &);


#endif  // _2018ICPC_NEERC_H_beros_H_INCLUDE
