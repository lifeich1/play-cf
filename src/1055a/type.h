#ifndef _1055a_metro_H_INCLUDE
#define _1055a_metro_H_INCLUDE

struct _1055a_metro_in_t;
struct _1055a_metro_out_t;

namespace licf {
namespace metro_1055a {
    typedef struct _1055a_metro_in_t _in_t;
    typedef struct _1055a_metro_out_t _out_t;
    typedef struct _1055a_metro_out_t _data_t;

    // placeholder
}
}

struct _1055a_metro_in_t {
    int n, s;
    int a[1010];
    int b[1010];
};

struct _1055a_metro_out_t {
    const struct _1055a_metro_in_t * in_;

    bool flag;
    int u[1010];
    int lis[1010];
};

typedef struct _1055a_metro_in_t _1055a_metro_in_t;
typedef struct _1055a_metro_out_t _1055a_metro_out_t;

extern int
metro_1055a(const _1055a_metro_in_t &, _1055a_metro_out_t &);


#endif  // _1055a_metro_H_INCLUDE
