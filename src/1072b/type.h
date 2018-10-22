#ifndef _1072b_curiosity_H_INCLUDE
#define _1072b_curiosity_H_INCLUDE

namespace licf {
namespace curiosity_1072b {
    // placeholder
}
}

struct _1072b_curiosity_in_t {
    int n;
    int a[100100];
    int b[100100];
};

struct _1072b_curiosity_out_t {
    bool flag;
    int res[100101];
};

typedef struct _1072b_curiosity_in_t _1072b_curiosity_in_t;
typedef struct _1072b_curiosity_out_t _1072b_curiosity_out_t;

extern int
curiosity_1072b(const _1072b_curiosity_in_t &, _1072b_curiosity_out_t &);


#endif  // _1072b_curiosity_H_INCLUDE
