#ifndef _1106b_ford_H_INCLUDE
#define _1106b_ford_H_INCLUDE

struct _1106b_ford_in_t;
struct _1106b_ford_out_t;

namespace licf {
namespace ford_1106b {
    typedef struct _1106b_ford_in_t _in_t;
    typedef struct _1106b_ford_out_t _out_t;
    typedef struct _1106b_ford_out_t _data_t;

    typedef long long LL;
    extern const int *abase;
    extern bool cmp_base(const int &lhs, const int &rhs);
}
}

struct _1106b_ford_in_t {
    int n, m;
    int a[100100], c[100100];
    int t[100100], d[100100];
};

struct _1106b_ford_out_t {
    const struct _1106b_ford_in_t * in_;

    long long ans[100100];
    int h[100100];
    int a[100100];
};

typedef struct _1106b_ford_in_t _1106b_ford_in_t;
typedef struct _1106b_ford_out_t _1106b_ford_out_t;

extern int
ford_1106b(const _1106b_ford_in_t &, _1106b_ford_out_t &);


#endif  // _1106b_ford_H_INCLUDE

