#ifndef _1055c_lucd_H_INCLUDE
#define _1055c_lucd_H_INCLUDE

struct _1055c_lucd_in_t;
struct _1055c_lucd_out_t;

namespace licf {
namespace lucd_1055c {
    typedef struct _1055c_lucd_in_t _in_t;
    typedef struct _1055c_lucd_out_t _out_t;
    typedef struct _1055c_lucd_out_t _data_t;

    int gcd(int, int);
    int interval(int, int, int, int);
}
}

struct _1055c_lucd_in_t {
    int la, ra, ta;
    int lb, rb, tb;
};

struct _1055c_lucd_out_t {
    const struct _1055c_lucd_in_t * in_;

    int res;
};

typedef struct _1055c_lucd_in_t _1055c_lucd_in_t;
typedef struct _1055c_lucd_out_t _1055c_lucd_out_t;

extern int
lucd_1055c(const _1055c_lucd_in_t &, _1055c_lucd_out_t &);


#endif  // _1055c_lucd_H_INCLUDE
