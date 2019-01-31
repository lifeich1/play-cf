#ifndef _1106d_wand_H_INCLUDE
#define _1106d_wand_H_INCLUDE
#include <vector>

struct _1106d_wand_in_t;
struct _1106d_wand_out_t;

namespace licf {
namespace wand_1106d {
    typedef struct _1106d_wand_in_t _in_t;
    typedef struct _1106d_wand_out_t _out_t;
    typedef struct _1106d_wand_out_t _data_t;

    // placeholder
}
}

struct _1106d_wand_in_t {
    int n, m;
    std::vector<int> e[100100];
};

struct _1106d_wand_out_t {
    const struct _1106d_wand_in_t * in_;

    int u[100100];
    int ans[100100];
};

typedef struct _1106d_wand_in_t _1106d_wand_in_t;
typedef struct _1106d_wand_out_t _1106d_wand_out_t;

extern int
wand_1106d(const _1106d_wand_in_t &, _1106d_wand_out_t &);


#endif  // _1106d_wand_H_INCLUDE

