#include "type.h"
#include <cstdio>

using namespace std;

_1066a_vova_in_t in_;
_1066a_vova_out_t out_;

static bool _read(int *L, int *v, int *l, int *r)
{
    if (in_.n <= 0) return false;
    in_.n --;
    return scanf("%d%d%d%d", L, v, l, r) == 4;
}

static void _put(int res)
{
    printf("%d\n", res);
}

void _get_input()
{
    scanf("%d", &in_.n);
    in_.read = _read;
    in_.put = _put;
}

void _print_output()
{
    // placeholder
}

int main(int argc, char *argv[])
{
    _get_input();
    vova_1066a(in_, out_);
    _print_output();
    return 0;
}
