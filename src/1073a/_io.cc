#include "type.h"
#include <cstdio>

using namespace std;

_1073a_dsub_in_t in_;
_1073a_dsub_out_t out_;

void _get_input()
{
    scanf("%d", &in_.n);
    scanf("%s", in_.s);
}

void _print_output()
{
    if (out_.flag)
    {
        printf("YES\n");
        for (int i = out_.l; i < out_.r; ++i)
            putchar(in_.s[i]);
        printf("\n");
    }
    else
        printf("NO\n");
}

int main(int argc, char *argv[])
{
    _get_input();
    dsub_1073a(in_, out_);
    _print_output();
    return 0;
}
