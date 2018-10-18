#include "type.h"
#include <cstdio>

using namespace std;

_1066b_heaters_in_t in_;
_1066b_heaters_out_t out_;

void _get_input()
{
    int n;
    scanf("%d%d", &n, &in_.r);
    in_.n = n;
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", in_.a + i);
    }
}

void _print_output()
{
    printf("%d\n", out_.res);
}

int main(int argc, char *argv[])
{
    _get_input();
    heaters_1066b(in_, out_);
    _print_output();
    return 0;
}
