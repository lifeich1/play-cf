//-[
#include "type.h"
//-]
#include <cstdio>

using namespace std;

_1106a_lcross_in_t in_;
_1106a_lcross_out_t out_ = {&in_};

void _get_input()
{
    static char s[512];
    scanf("%d", &in_.n);
    for (int i = 0; i < in_.n; ++i)
    {
        scanf("%s", s);
        for (int j = 0; j < in_.n; ++j)
            in_.a[i][j] = s[j];
    }
}

void _print_output()
{
    printf("%d\n", out_.ans);
}

int main(int argc, char *argv[])
{
    _get_input();
    lcross_1106a(in_, out_);
    _print_output();
    return 0;
}

