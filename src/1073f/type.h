#ifndef _1073f_ch2pa_H_INCLUDE
#define _1073f_ch2pa_H_INCLUDE

struct _1073f_ch2pa_in_t;
struct _1073f_ch2pa_out_t;

namespace licf {
namespace ch2pa_1073f {
    typedef struct _1073f_ch2pa_in_t _in_t;
    typedef struct _1073f_ch2pa_out_t _out_t;
    typedef struct _1073f_ch2pa_out_t _data_t;

    struct edge {
        int y;
        edge * nx;

        edge() {}
        edge(int, edge *);
    };

    void addEdge(edge **, int);
}
}

struct _1073f_ch2pa_in_t {
    int n;
    int e[200100][2];
};

struct _1073f_ch2pa_out_t {
    const struct _1073f_ch2pa_in_t * in_;

    int ans[4];
    int degree[200100];
    edge * eh[200100]; // edge link list head
    int goodSt[200100]; // if have at least 2 good path 3+ degree point
    int goodVal[200100][2]; // 2 max good path value
    int goodTag[200100][2]; // 2 max good path tag
    bool ingood[200100]; // if in good path
};

typedef struct _1073f_ch2pa_in_t _1073f_ch2pa_in_t;
typedef struct _1073f_ch2pa_out_t _1073f_ch2pa_out_t;

extern int
ch2pa_1073f(const _1073f_ch2pa_in_t &, _1073f_ch2pa_out_t &);


#endif  // _1073f_ch2pa_H_INCLUDE
