#ifndef _1077a_frgj_H_INCLUDE
#define _1077a_frgj_H_INCLUDE

struct _1077a_frgj_in_t;
struct _1077a_frgj_out_t;

namespace licf {
namespace frgj_1077a {
    typedef struct _1077a_frgj_in_t _in_t;
    typedef struct _1077a_frgj_out_t _out_t;
    typedef struct _1077a_frgj_out_t _data_t;

    // placeholder
}
}

struct _1077a_frgj_in_t {
    int (*get)(int *, int *, int *);
    void (*put)(long long);
};

struct _1077a_frgj_out_t {
    const struct _1077a_frgj_in_t * in_;

    // placeholder
};

typedef struct _1077a_frgj_in_t _1077a_frgj_in_t;
typedef struct _1077a_frgj_out_t _1077a_frgj_out_t;

extern int
frgj_1077a(const _1077a_frgj_in_t &, _1077a_frgj_out_t &);


#endif  // _1077a_frgj_H_INCLUDE

