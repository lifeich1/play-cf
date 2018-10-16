#ifndef _1066d_bpk_H_INCLUDE
#define _1066d_bpk_H_INCLUDE

struct _1066d_bpk_in_t {
    int n,m,k;
    int a[200100];
};

struct _1066d_bpk_out_t {
    int res;
};

typedef struct _1066d_bpk_in_t _1066d_bpk_in_t;
typedef struct _1066d_bpk_out_t _1066d_bpk_out_t;

extern int
bpk_1066d(const _1066d_bpk_in_t &, _1066d_bpk_out_t &);


#endif  // _1066d_bpk_H_INCLUDE
