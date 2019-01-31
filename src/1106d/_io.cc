//-[
#include "type.h"
//-]
#include <cstdio>

using namespace std;

_1106d_wand_in_t in_;
_1106d_wand_out_t out_ = {&in_};

void _get_input()
{
    scanf("%d%d", &in_.n, &in_.m);
    for (int i = 0; i < in_.m; ++i)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        x--, y--;
        in_.e[x].push_back(y);
        in_.e[y].push_back(x);
    }
}

void _print_output()
{
    for (int i = 0; i < in_.n; ++i)
        printf("%d ", out_.ans[i] + 1);
    printf("\n");
}

int main(int argc, char *argv[])
{
    _get_input();
    wand_1106d(in_, out_);
    _print_output();
    return 0;
}

