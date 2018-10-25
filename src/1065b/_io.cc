#include "type.h"
#include <cstdio>

using namespace std;

_1065b_isol_in_t in_;
_1065b_isol_out_t out_;

void _get_input()
{
    scanf("%d%lld", &in_.n, &in_.m);
}

void _print_output()
{
    printf("%d %d\n", out_.res[0], out_.res[1]);
}

int main(int argc, char *argv[])
{
    _get_input();
    isol_1065b(in_, out_);
    _print_output();
    return 0;
}
