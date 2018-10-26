#include "type.h"
#include <cstdio>

using namespace std;

_1073b_vabook_in_t in_;
_1073b_vabook_out_t out_;

void _get_input()
{
    int n;
    scanf("%d", &n);
    in_.n = n;
    for (int i = 0; i < n; ++i)
        scanf("%d", in_.a + i);
    for (int i = 0; i < n; ++i)
        scanf("%d", in_.b + i);
}

void _print_output()
{
    for (int i = 0; i < in_.n; ++i)
        printf("%d ", out_.res[i]);
    printf("\n");
}

int main(int argc, char *argv[])
{
    _get_input();
    vabook_1073b(in_, out_);
    _print_output();
    return 0;
}
