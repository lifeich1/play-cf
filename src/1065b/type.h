#ifndef _1065b_isol_H_INCLUDE
#define _1065b_isol_H_INCLUDE

struct _1065b_isol_in_t;
struct _1065b_isol_out_t;

namespace licf {
namespace isol_1065b {
    typedef struct _1065b_isol_in_t _in_t;
    typedef struct _1065b_isol_out_t _out_t;

    typedef long long LL;
}
}

struct _1065b_isol_in_t {
    int n;
    long long m;
};

struct _1065b_isol_out_t {
    int res[2];
};

typedef struct _1065b_isol_in_t _1065b_isol_in_t;
typedef struct _1065b_isol_out_t _1065b_isol_out_t;

extern int
isol_1065b(const _1065b_isol_in_t &, _1065b_isol_out_t &);


#endif  // _1065b_isol_H_INCLUDE
