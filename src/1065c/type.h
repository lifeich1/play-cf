#ifndef _1065c_mie_H_INCLUDE
#define _1065c_mie_H_INCLUDE

struct _1065c_mie_in_t;
struct _1065c_mie_out_t;

namespace licf {
namespace mie_1065c {
    typedef struct _1065c_mie_in_t _in_t;
    typedef struct _1065c_mie_out_t _out_t;

    typedef long long LL;
}
}

struct _1065c_mie_in_t {
    int n, k;
    int a[200100];
};

struct _1065c_mie_out_t {
    int res;
    int a[200100];
    long long s[200100];
};

typedef struct _1065c_mie_in_t _1065c_mie_in_t;
typedef struct _1065c_mie_out_t _1065c_mie_out_t;

extern int
mie_1065c(const _1065c_mie_in_t &, _1065c_mie_out_t &);


#endif  // _1065c_mie_H_INCLUDE
