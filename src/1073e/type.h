#ifndef _1073e_segs_H_INCLUDE
#define _1073e_segs_H_INCLUDE

struct _1073e_segs_in_t;
struct _1073e_segs_out_t;

namespace licf {
namespace segs_1073e {
    typedef struct _1073e_segs_in_t _in_t;
    typedef struct _1073e_segs_out_t _out_t;

    typedef long long LL;
    typedef int dpf_t[20][1024];
    typedef dpf_t & reff_t;

    extern const int modn;

    extern void reset_f(reff_t f);
    extern void subcalc(LL N, _out_t & out_, int K);
}
}

struct _1073e_segs_in_t {
    long long l, r;
    int k;
};

struct _1073e_segs_out_t {
    int res;
    int fu[20][1024];
    int cu[20][1024];
    int dig[1024];
    int f[20][1024];
    int c[20][1024];
    int d10[20];
};

typedef struct _1073e_segs_in_t _1073e_segs_in_t;
typedef struct _1073e_segs_out_t _1073e_segs_out_t;

extern int
segs_1073e(const _1073e_segs_in_t &, _1073e_segs_out_t &);


#endif  // _1073e_segs_H_INCLUDE
