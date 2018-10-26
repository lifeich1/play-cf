#ifndef _1073d_berl_H_INCLUDE
#define _1073d_berl_H_INCLUDE

struct _1073d_berl_in_t;
struct _1073d_berl_out_t;

namespace licf {
namespace berl_1073d {
    typedef struct _1073d_berl_in_t _in_t;
    typedef struct _1073d_berl_out_t _out_t;

    typedef long long LL;

    void insert(LL *a, int n, int x, LL v);
    int lowerBound(LL *a, int n, LL v);
    LL sumUp(LL *a, int n, int x);
}
}

struct _1073d_berl_in_t {
    long long T;
    int n;
    int a[200100];
};

struct _1073d_berl_out_t {
    long long s[200100];
    long long c[200100];
    long long res;
};

typedef struct _1073d_berl_in_t _1073d_berl_in_t;
typedef struct _1073d_berl_out_t _1073d_berl_out_t;

extern int
berl_1073d(const _1073d_berl_in_t &, _1073d_berl_out_t &);


#endif  // _1073d_berl_H_INCLUDE
