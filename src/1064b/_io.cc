#include "type.h"
#include <cstdio>

using namespace std;

_1064b_emm_in_t in_;
_1064b_emm_out_t out_;

bool _read(int *n)
{
    if (in_.t > 0)
    {
        in_.t --;
        return scanf("%d", n) == 1;
    }
    else
        return false;
}

void _put(long long res)
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
    emm_1064b(in_, out_);
    _print_output();
    return 0;
}
