#ifndef $tmacro
#define $tmacro

struct $tin;
struct $tout;

namespace licf {
namespace $tfunc {
    typedef struct $tin _in_t;
    typedef struct $tout _out_t;
    typedef struct $tout _data_t;

    // placeholder
}
}

struct $tin {
    int __padding;
};

struct $tout {
    const struct $tin * in_;

    // placeholder
};

typedef struct $tin $tin;
typedef struct $tout $tout;

extern int
$tfunc(const $tin &, $tout &);


#endif  // $tmacro

