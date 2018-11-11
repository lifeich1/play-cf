#include "type.h"
#include <cstdio>

using namespace std;

_1055c_lucd_in_t in_;
_1055c_lucd_out_t out_ = {&in_};

void _get_input()
{
    scanf("%d%d%d", &in_.la, &in_.ra, &in_.ta);
    scanf("%d%d%d", &in_.lb, &in_.rb, &in_.tb);
}

void _print_output()
{
    printf("%d\n", out_.res);
}

int main(int argc, char *argv[])
{
    _get_input();
    lucd_1055c(in_, out_);
    _print_output();
    return 0;
}
