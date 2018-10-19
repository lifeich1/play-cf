#include "type.h"
#include <cstdio>

using namespace std;

_1066f_ya2w_in_t in_;
_1066f_ya2w_out_t out_;

void _get_input()
{
    int n;
    scanf("%d", &n);
    in_.n = n;
    for (int i = 0; i < n; ++i)
    {
        scanf("%d%d", in_.x + i, in_.y + i);
    }
}

void _print_output()
{
    printf("%lld\n", out_.res);
}

int main(int argc, char *argv[])
{
    _get_input();
    ya2w_1066f(in_, out_);
    _print_output();
    return 0;
}
