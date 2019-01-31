#ifndef _1106c_ndiv_H_INCLUDE
#define _1106c_ndiv_H_INCLUDE

struct _1106c_ndiv_in_t;
struct _1106c_ndiv_out_t;

namespace licf {
namespace ndiv_1106c {
    typedef struct _1106c_ndiv_in_t _in_t;
    typedef struct _1106c_ndiv_out_t _out_t;
    typedef struct _1106c_ndiv_out_t _data_t;

    typedef long long LL;
}
}

struct _1106c_ndiv_in_t {
    int n;
    int a[300100];
};

struct _1106c_ndiv_out_t {
    const struct _1106c_ndiv_in_t * in_;

    int a[300100];
    long long ans;
};

typedef struct _1106c_ndiv_in_t _1106c_ndiv_in_t;
typedef struct _1106c_ndiv_out_t _1106c_ndiv_out_t;

extern int
ndiv_1106c(const _1106c_ndiv_in_t &, _1106c_ndiv_out_t &);


#endif  // _1106c_ndiv_H_INCLUDE

