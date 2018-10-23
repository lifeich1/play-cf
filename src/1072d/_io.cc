#include "type.h"
#include <cstdio>

using namespace std;

_1072d_minipath_in_t in_;
_1072d_minipath_out_t out_;

void _get_input()
{
    int n, K;
    scanf("%d%d", &n, &K);
    in_.n = n;
    in_.K = K;
    for (int i = 0; i < n; ++i)
        scanf("%s", in_.wd[i]);
}

void _print_output()
{
    out_.res[in_.n * 2 - 1] = '\0';
    printf("%s\n", out_.res);
}

int main(int argc, char *argv[])
{
    _get_input();
    minipath_1072d(in_, out_);
    _print_output();
    return 0;
}
