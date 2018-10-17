#ifndef _1066c_bkq_H_INCLUDE
#define _1066c_bkq_H_INCLUDE

struct _1066c_bkq_in_t {
    bool (*get)(int *op, int *id);
};

struct _1066c_bkq_out_t {
    void (*put)(int popc);
    int l[200100];
    int r[200100];
};

typedef struct _1066c_bkq_in_t _1066c_bkq_in_t;
typedef struct _1066c_bkq_out_t _1066c_bkq_out_t;

extern int
bkq_1066c(const _1066c_bkq_in_t &, _1066c_bkq_out_t &);


#endif  // _1066c_bkq_H_INCLUDE
