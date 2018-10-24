#ifndef _1064a_triangle_H_INCLUDE
#define _1064a_triangle_H_INCLUDE

struct _1064a_triangle_in_t;
struct _1064a_triangle_out_t;

namespace licf {
namespace triangle_1064a {
    typedef struct _1064a_triangle_in_t _in_t;
    typedef struct _1064a_triangle_out_t _out_t;

    // placeholder
}
}

struct _1064a_triangle_in_t {
    int a, b, c;
};

struct _1064a_triangle_out_t {
    int res;
};

typedef struct _1064a_triangle_in_t _1064a_triangle_in_t;
typedef struct _1064a_triangle_out_t _1064a_triangle_out_t;

extern int
triangle_1064a(const _1064a_triangle_in_t &, _1064a_triangle_out_t &);


#endif  // _1064a_triangle_H_INCLUDE
