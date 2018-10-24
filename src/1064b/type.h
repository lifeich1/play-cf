#ifndef _1064b_emm_H_INCLUDE
#define _1064b_emm_H_INCLUDE

struct _1064b_emm_in_t;
struct _1064b_emm_out_t;

namespace licf {
namespace emm_1064b {
    typedef struct _1064b_emm_in_t _in_t;
    typedef struct _1064b_emm_out_t _out_t;

    typedef long long LL;
}
}

struct _1064b_emm_in_t {
    int t;
    bool (*read)(int *);
    void (*put)(long long);
};

struct _1064b_emm_out_t {
    int __padding;
};

typedef struct _1064b_emm_in_t _1064b_emm_in_t;
typedef struct _1064b_emm_out_t _1064b_emm_out_t;

extern int
emm_1064b(const _1064b_emm_in_t &, _1064b_emm_out_t &);


#endif  // _1064b_emm_H_INCLUDE
