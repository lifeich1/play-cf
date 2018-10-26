#ifndef _1073c_varobot_H_INCLUDE
#define _1073c_varobot_H_INCLUDE

struct _1073c_varobot_in_t;
struct _1073c_varobot_out_t;

namespace licf {
namespace varobot_1073c {
    typedef struct _1073c_varobot_in_t _in_t;
    typedef struct _1073c_varobot_out_t _out_t;

    bool isReachable(int n, int x0, int y0, int x1, int y1);
}
}

struct _1073c_varobot_in_t {
    int n, x, y;
    char s[200100];
};

struct _1073c_varobot_out_t {
    int res;
    int d[200100][2];
};

typedef struct _1073c_varobot_in_t _1073c_varobot_in_t;
typedef struct _1073c_varobot_out_t _1073c_varobot_out_t;

extern int
varobot_1073c(const _1073c_varobot_in_t &, _1073c_varobot_out_t &);


#endif  // _1073c_varobot_H_INCLUDE
