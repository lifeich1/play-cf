#ifndef _1072c_cram_H_INCLUDE
#define _1072c_cram_H_INCLUDE

namespace licf {
namespace cram_1072c {
    /**
     * 利用归纳法可知[1, n(n+1)/2]内的数字均为{1...n}子集的和
     */
    typedef long long LL;
}
}

struct _1072c_cram_in_t {
    int a, b;
};

struct _1072c_cram_out_t {
    int n, p, q;
    int flag[70000];
};

typedef struct _1072c_cram_in_t _1072c_cram_in_t;
typedef struct _1072c_cram_out_t _1072c_cram_out_t;

extern int
cram_1072c(const _1072c_cram_in_t &, _1072c_cram_out_t &);


#endif  // _1072c_cram_H_INCLUDE
