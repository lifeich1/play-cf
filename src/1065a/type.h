#ifndef _1065a_vasya_H_INCLUDE
#define _1065a_vasya_H_INCLUDE

struct _1065a_vasya_in_t;
struct _1065a_vasya_out_t;

namespace licf {
namespace vasya_1065a {
    typedef struct _1065a_vasya_in_t _in_t;
    typedef struct _1065a_vasya_out_t _out_t;

    typedef long long LL;
}
}

struct _1065a_vasya_in_t {
    int t;
    bool (*read)(int *, int *, int *, int *);
    void (*put)(long long);
};

struct _1065a_vasya_out_t {
    int __padding;
};

typedef struct _1065a_vasya_in_t _1065a_vasya_in_t;
typedef struct _1065a_vasya_out_t _1065a_vasya_out_t;

extern int
vasya_1065a(const _1065a_vasya_in_t &, _1065a_vasya_out_t &);


#endif  // _1065a_vasya_H_INCLUDE
