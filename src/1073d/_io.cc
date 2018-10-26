#include "type.h"
#include <cstdio>

using namespace std;

_1073d_berl_in_t in_;
_1073d_berl_out_t out_;

void _get_input()
{
    int n;
    scanf("%d%lld", &n, &in_.T);
    in_.n = n;
    for (int i = 0; i < n; ++i)
        scanf("%d", in_.a + i);
}

void _print_output()
{
    printf("%lld\n", out_.res);
}

int main(int argc, char *argv[])
{
    _get_input();
    berl_1073d(in_, out_);
    _print_output();
    return 0;
}
