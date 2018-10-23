#ifndef _1072d_minipath_H_INCLUDE
#define _1072d_minipath_H_INCLUDE

namespace licf {
namespace minipath_1072d {
    struct tour_node {
        int x, y;
        int *_k;
        tour_node(int x_, int y_);
        tour_node(): tour_node(0, 0) {}

        int k() const;
        void setkp(int *k);
    };

    extern void 
        visit_(int x, int y, int k, int & u, int step
                , int & f, int & cnt, tour_node * lis);
}
}

struct _1072d_minipath_in_t {
    int n, K;
    char wd[2010][2010];
};

struct _1072d_minipath_out_t {
    char res[4000];
    licf::minipath_1072d::tour_node lis[2][4000];
    int f[2010][2010];
    int u[2010][2010];
};

typedef struct _1072d_minipath_in_t _1072d_minipath_in_t;
typedef struct _1072d_minipath_out_t _1072d_minipath_out_t;

extern int
minipath_1072d(const _1072d_minipath_in_t &, _1072d_minipath_out_t &);


#endif  // _1072d_minipath_H_INCLUDE
