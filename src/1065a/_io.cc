#include "type.h"
#include <cstdio>

using namespace std;

_1065a_vasya_in_t in_;
_1065a_vasya_out_t out_;

static bool _read(int *s, int *a, int *b, int *c)
{
    if (in_.t > 0)
    {
        in_.t --;
        return scanf("%d%d%d%d", s, a, b, c) == 4;
    }
    else
        return false;
}

static void _put(long long res)
{
    printf("%lld\n", res);
}

void _get_input()
{
    scanf("%d", &in_.t);
    in_.read = _read;
    in_.put = _put;
}

void _print_output()
{
    // placeholder
}

int main(int argc, char *argv[])
{
    _get_input();
    vasya_1065a(in_, out_);
    _print_output();
    return 0;
}
