#include "type.h"
#include <cstdio>

using namespace std;

_1055b_ahair_in_t in_;
_1055b_ahair_out_t out_ = {&in_};

static int getop(int *p, int *d)
{
    int op;
    scanf("%d", &op);
    if (op != 0)
    {
        scanf("%d%d", p, d);
    }
    return op;
}

static void putr(int r)
{
    printf("%d\n", r);
}

void _get_input()
{
    in_.get = getop;
    in_.put = putr;
    scanf("%d%d%d", &in_.n, &in_.m, &in_.l);
    for (int i = 0; i < in_.n; ++i)
        scanf("%d", &out_.a[i]);
}

void _print_output()
{
    // placeholder
}

int main(int argc, char *argv[])
{
    _get_input();
    ahair_1055b(in_, out_);
    _print_output();
    return 0;
}
