#include "type.h"
#include <cstdio>

using namespace std;

_1073e_segs_in_t in_;
_1073e_segs_out_t out_;

void _get_input()
{
    scanf("%lld%lld%d", &in_.l, &in_.r, &in_.k);
}

void _print_output()
{
    printf("%d\n", out_.res);
}

int main(int argc, char *argv[])
{
    _get_input();
    segs_1073e(in_, out_);
    _print_output();
    return 0;
}
