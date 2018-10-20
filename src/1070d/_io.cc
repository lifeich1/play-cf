#include "type.h"
#include <cstdio>

using namespace std;

_2018ICPC_NEERC_D_gardis_in_t in_;
_2018ICPC_NEERC_D_gardis_out_t out_;

void _get_input()
{
    int n, k;
    scanf("%d%d", &n, &k);
    in_.n = n;
    in_.k = k;
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", in_.a + i);
    }
}

void _print_output()
{
    printf("%lld\n", out_.res);
}

int main(int argc, char *argv[])
{
    _get_input();
    gardis_2018ICPC_NEERC_D(in_, out_);
    _print_output();
    return 0;
}
