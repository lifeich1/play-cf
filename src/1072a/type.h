#ifndef _1072a_plate_H_INCLUDE
#define _1072a_plate_H_INCLUDE

namespace licf {
namespace plate_1072a {
    // placeholder
}
}

struct _1072a_plate_in_t {
    int n, m, k;
};

struct _1072a_plate_out_t {
    int res;
};

typedef struct _1072a_plate_in_t _1072a_plate_in_t;
typedef struct _1072a_plate_out_t _1072a_plate_out_t;

extern int
plate_1072a(const _1072a_plate_in_t &, _1072a_plate_out_t &);


#endif  // _1072a_plate_H_INCLUDE
