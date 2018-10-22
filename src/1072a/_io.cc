#include "type.h"
#include <cstdio>

using namespace std;

_1072a_plate_in_t in_;
_1072a_plate_out_t out_;

void _get_input()
{
    scanf("%d%d%d", &in_.n, &in_.m, &in_.k);
}

void _print_output()
{
    printf("%d\n", out_.res);
}

int main(int argc, char *argv[])
{
    _get_input();
    plate_1072a(in_, out_);
    _print_output();
    return 0;
}
