#ifndef _2018ICPC_NEERC_K_vpst_H_INCLUDE
#define _2018ICPC_NEERC_K_vpst_H_INCLUDE

namespace licf {
namespace vpst_2018ICPC_NEERC_K {
    // placeholder
}
}

struct _2018ICPC_NEERC_K_vpst_in_t {
    int n, k;
    int a[100100];
};

struct _2018ICPC_NEERC_K_vpst_out_t {
    int res[100100];
    bool flag; 
};

typedef struct _2018ICPC_NEERC_K_vpst_in_t _2018ICPC_NEERC_K_vpst_in_t;
typedef struct _2018ICPC_NEERC_K_vpst_out_t _2018ICPC_NEERC_K_vpst_out_t;

extern int
vpst_2018ICPC_NEERC_K(const _2018ICPC_NEERC_K_vpst_in_t &, _2018ICPC_NEERC_K_vpst_out_t &);


#endif  // _2018ICPC_NEERC_K_vpst_H_INCLUDE
