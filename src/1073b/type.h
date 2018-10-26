#ifndef _1073b_vabook_H_INCLUDE
#define _1073b_vabook_H_INCLUDE

struct _1073b_vabook_in_t;
struct _1073b_vabook_out_t;

namespace licf {
namespace vabook_1073b {
    typedef struct _1073b_vabook_in_t _in_t;
    typedef struct _1073b_vabook_out_t _out_t;

    // placeholder
}
}

struct _1073b_vabook_in_t {
    int n;
    int a[200100];
    int b[200100];
};

struct _1073b_vabook_out_t {
    int res[200100];
    int pos[200100];
};

typedef struct _1073b_vabook_in_t _1073b_vabook_in_t;
typedef struct _1073b_vabook_out_t _1073b_vabook_out_t;

extern int
vabook_1073b(const _1073b_vabook_in_t &, _1073b_vabook_out_t &);


#endif  // _1073b_vabook_H_INCLUDE
