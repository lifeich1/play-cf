#ifndef _1066a_vova_H_INCLUDE
#define _1066a_vova_H_INCLUDE

struct _1066a_vova_in_t;
struct _1066a_vova_out_t;

namespace licf {
namespace vova_1066a {
    typedef struct _1066a_vova_in_t _in_t;
    typedef struct _1066a_vova_out_t _out_t;

    // placeholder
}
}

struct _1066a_vova_in_t {
    int n;
    bool (*read)(int *, int *, int *, int *);
    void (*put)(int);
};

struct _1066a_vova_out_t {
    int __padding;
};

typedef struct _1066a_vova_in_t _1066a_vova_in_t;
typedef struct _1066a_vova_out_t _1066a_vova_out_t;

extern int
vova_1066a(const _1066a_vova_in_t &, _1066a_vova_out_t &);


#endif  // _1066a_vova_H_INCLUDE
