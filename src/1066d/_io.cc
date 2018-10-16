#include "type.h"
#include <cstdio>

using namespace std;

_1066d_bpk_in_t in_;
_1066d_bpk_out_t out_;

void _get_input()
{
    scanf("%d%d%d", &in_.n, &in_.m, &in_.k);
    for (int i = 0; i < in_.n; ++i)
    {
        scanf("%d", in_.a + i);
    }
}

void _print_output()
{
    printf("%d\n", out_.res);
}

int main(int argc, char *argv[])
{
    _get_input();
    bpk_1066d(in_, out_);
    _print_output();
    return 0;
}
