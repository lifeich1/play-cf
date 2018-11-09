#ifndef _1054a_elest_H_INCLUDE
#define _1054a_elest_H_INCLUDE

struct _1054a_elest_in_t;
struct _1054a_elest_out_t;

namespace licf {
namespace elest_1054a {
    typedef struct _1054a_elest_in_t _in_t;
    typedef struct _1054a_elest_out_t _out_t;
    typedef struct _1054a_elest_out_t _data_t;

    extern int abs(int);
}
}

struct _1054a_elest_in_t {
    int x, y, z, t1, t2, t3;
};

struct _1054a_elest_out_t {
    const struct _1054a_elest_in_t * in_;

    bool flag;
};

typedef struct _1054a_elest_in_t _1054a_elest_in_t;
typedef struct _1054a_elest_out_t _1054a_elest_out_t;

extern int
elest_1054a(const _1054a_elest_in_t &, _1054a_elest_out_t &);


#endif  // _1054a_elest_H_INCLUDE
