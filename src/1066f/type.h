#ifndef _1066f_ya2w_H_INCLUDE
#define _1066f_ya2w_H_INCLUDE

namespace licf {
namespace ya2w_1066f {
    struct point {
        int x, y;
        point(): point(0, 0) {}
        point(int x_, int y_): x(x_), y(y_) {}
        int u() const { return x + y; }
        int v() const { return x - y; }
    };

    bool operator< (const point & lhs, const point & rhs);

    typedef long long _int64;

    _int64 dist(const point & lhs, const point & rhs);
}
}

struct _1066f_ya2w_in_t {
    int n;
    int x[200100];
    int y[200100];
};

struct _1066f_ya2w_out_t {
    licf::ya2w_1066f::point p[200100];
    long long res;
};

typedef struct _1066f_ya2w_in_t _1066f_ya2w_in_t;
typedef struct _1066f_ya2w_out_t _1066f_ya2w_out_t;

extern int
ya2w_1066f(const _1066f_ya2w_in_t &, _1066f_ya2w_out_t &);


#endif  // _1066f_ya2w_H_INCLUDE
