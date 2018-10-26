#include "type.h"
#include <cstdio>

using namespace std;

_1073c_varobot_in_t in_;
_1073c_varobot_out_t out_;

void _get_input()
{
    scanf("%d", &in_.n);
    scanf("%s", in_.s);
    scanf("%d%d", &in_.x, &in_.y);
}

void _print_output()
{
    printf("%d\n", out_.res);
}

int main(int argc, char *argv[])
{
    _get_input();
    varobot_1073c(in_, out_);
    _print_output();
    return 0;
}
