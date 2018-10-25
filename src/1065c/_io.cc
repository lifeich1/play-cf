#include "type.h"
#include <cstdio>

using namespace std;

_1065c_mie_in_t in_;
_1065c_mie_out_t out_;

void _get_input()
{
    int n;
    scanf("%d%d", &n, &in_.k);
    in_.n = n;
    for (int i = 0; i < n; ++i)
        scanf("%d", in_.a + i);
}

void _print_output()
{
    printf("%d\n", out_.res);
}

int main(int argc, char *argv[])
{
    _get_input();
    mie_1065c(in_, out_);
    _print_output();
    return 0;
}
