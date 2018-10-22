#include "type.h"
#include <cstdio>

using namespace std;

_1072b_curiosity_in_t in_;
_1072b_curiosity_out_t out_;

void _get_input()
{
    int n;
    scanf("%d", &n);
    -- n;
    in_.n = n;
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", in_.a + i);
    }
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", in_.b + i);
    }
}

void _print_output()
{
    if (out_.flag)
    {
        printf("YES\n");
        for (int i = 0; i <= in_.n; ++i)
            printf("%d ", out_.res[i]);
        printf("\n");
    }
    else
        printf("NO\n");
}

int main(int argc, char *argv[])
{
    _get_input();
    curiosity_1072b(in_, out_);
    _print_output();
    return 0;
}
