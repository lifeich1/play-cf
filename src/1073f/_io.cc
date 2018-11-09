#include "type.h"
#include <cstdio>

using namespace std;

_1073f_ch2pa_in_t in_;
_1073f_ch2pa_out_t out_ = {&in_};

void _get_input()
{
    scanf("%d", &in_.n);
    for (int i = 0; i < in_.n - 1; ++i)
    {
        scanf("%d%d", in_.e[i], in_.e[i] + 1);
    }
}

void _print_output()
{
    printf("%d %d\n%d %d\n", out_.ans[0], out_.ans[1],
            out_.ans[2], out_.ans[3]);
}

int main(int argc, char *argv[])
{
    _get_input();
    ch2pa_1073f(in_, out_);
    _print_output();
    return 0;
}
