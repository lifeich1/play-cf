#include "type.h"
#include <cstdio>

using namespace std;

_1072c_cram_in_t in_;
_1072c_cram_out_t out_;

void _get_input()
{
    scanf("%d%d", &in_.a, &in_.b);
}

void _print_output()
{
    int n = out_.n;
    printf("%d\n", out_.p);
    for (int i = 1; i <= n; ++ i)
        if (out_.flag[i]) printf("%d ", i);
    printf("\n%d\n", out_.q);
    for (int i = 1; i <= n; ++ i)
        if (!out_.flag[i]) printf("%d ", i);
    printf("\n");
}

int main(int argc, char *argv[])
{
    _get_input();
    cram_1072c(in_, out_);
    _print_output();
    return 0;
}
