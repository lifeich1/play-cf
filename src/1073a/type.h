#ifndef _1073a_dsub_H_INCLUDE
#define _1073a_dsub_H_INCLUDE

struct _1073a_dsub_in_t;
struct _1073a_dsub_out_t;

namespace licf {
namespace dsub_1073a {
    typedef struct _1073a_dsub_in_t _in_t;
    typedef struct _1073a_dsub_out_t _out_t;

    // placeholder
}
}

struct _1073a_dsub_in_t {
    int n;
    char s[1010];
};

struct _1073a_dsub_out_t {
    bool flag;
    int l, r;
    int cnt[26];
};

typedef struct _1073a_dsub_in_t _1073a_dsub_in_t;
typedef struct _1073a_dsub_out_t _1073a_dsub_out_t;

extern int
dsub_1073a(const _1073a_dsub_in_t &, _1073a_dsub_out_t &);


#endif  // _1073a_dsub_H_INCLUDE
