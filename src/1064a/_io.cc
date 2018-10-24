#include "type.h"
#include <cstdio>

using namespace std;

_1064a_triangle_in_t in_;
_1064a_triangle_out_t out_;

void _get_input()
{
    scanf("%d%d%d", &in_.a, &in_.b, &in_.c);
}

void _print_output()
{
    printf("%d\n", out_.res);
}

int main(int argc, char *argv[])
{
    _get_input();
    triangle_1064a(in_, out_);
    _print_output();
    return 0;
}
