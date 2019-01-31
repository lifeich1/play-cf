#ifndef _1106a_lcross_H_INCLUDE
#define _1106a_lcross_H_INCLUDE

struct _1106a_lcross_in_t;
struct _1106a_lcross_out_t;

namespace licf {
namespace lcross_1106a {
    typedef struct _1106a_lcross_in_t _in_t;
    typedef struct _1106a_lcross_out_t _out_t;
    typedef struct _1106a_lcross_out_t _data_t;

    // placeholder
}
}

struct _1106a_lcross_in_t {
    int n;
    char a[512][512];
};

struct _1106a_lcross_out_t {
    const struct _1106a_lcross_in_t * in_;

    int ans;
};

typedef struct _1106a_lcross_in_t _1106a_lcross_in_t;
typedef struct _1106a_lcross_out_t _1106a_lcross_out_t;

extern int
lcross_1106a(const _1106a_lcross_in_t &, _1106a_lcross_out_t &);


#endif  // _1106a_lcross_H_INCLUDE

