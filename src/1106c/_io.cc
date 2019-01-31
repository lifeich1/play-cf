//-[
#include "type.h"
//-]
#include <cstdio>

using namespace std;

_1106c_ndiv_in_t in_;
_1106c_ndiv_out_t out_ = {&in_};

void _get_input()
{
    scanf("%d", &in_.n);
    for (int i = 0; i < in_.n; ++i) scanf("%d", &in_.a[i]);
}

void _print_output()
{
    printf("%lld\n", out_.ans);
}

int main(int argc, char *argv[])
{
    _get_input();
    ndiv_1106c(in_, out_);
    _print_output();
    return 0;
}

