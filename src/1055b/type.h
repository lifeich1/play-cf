#ifndef _1055b_ahair_H_INCLUDE
#define _1055b_ahair_H_INCLUDE

struct _1055b_ahair_in_t;
struct _1055b_ahair_out_t;

namespace licf {
namespace ahair_1055b {
    typedef struct _1055b_ahair_in_t _in_t;
    typedef struct _1055b_ahair_out_t _out_t;
    typedef struct _1055b_ahair_out_t _data_t;

    // placeholder
}
}

struct _1055b_ahair_in_t {
    int (*get)(int *, int *);
    void (*put)(int);

    int n, m, l;
};

struct _1055b_ahair_out_t {
    const struct _1055b_ahair_in_t * in_;

    int a[100100];
};

typedef struct _1055b_ahair_in_t _1055b_ahair_in_t;
typedef struct _1055b_ahair_out_t _1055b_ahair_out_t;

extern int
ahair_1055b(const _1055b_ahair_in_t &, _1055b_ahair_out_t &);


#endif  // _1055b_ahair_H_INCLUDE
