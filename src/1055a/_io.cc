#include "type.h"
#include <cstdio>

using namespace std;

_1055a_metro_in_t in_;
_1055a_metro_out_t out_ = {&in_};

void _get_input()
{
    int n;
    scanf("%d%d", &n, &in_.s);
    in_.n = n;
    for (int i = 0; i < n; ++i) scanf("%d", in_.a + i);
    for (int i = 0; i < n; ++i) scanf("%d", in_.b + i);
}

void _print_output()
{
    printf(out_.flag ? "YES" : "NO");
    putchar('\n');
}

int main(int argc, char *argv[])
{
    _get_input();
    metro_1055a(in_, out_);
    _print_output();
    return 0;
}
