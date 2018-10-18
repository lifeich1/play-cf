#ifndef _1066b_heaters_H_INCLUDE
#define _1066b_heaters_H_INCLUDE

struct _1066b_heaters_in_t {
    int n, r;
    int a[1010];
};

struct _1066b_heaters_out_t {
    int near[1010];
    int res;
};

typedef struct _1066b_heaters_in_t _1066b_heaters_in_t;
typedef struct _1066b_heaters_out_t _1066b_heaters_out_t;

extern int
heaters_1066b(const _1066b_heaters_in_t &, _1066b_heaters_out_t &);


#endif  // _1066b_heaters_H_INCLUDE
