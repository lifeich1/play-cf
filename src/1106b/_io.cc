//-[
#include "type.h"
//-]
#include <cstdio>

using namespace std;

_1106b_ford_in_t in_;
_1106b_ford_out_t out_ = {&in_};

void _get_input()
{
    int &n = in_.n;
    int &m = in_.m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i)
        scanf("%d", &in_.a[i]);
    for (int i = 0; i < n; ++i)
        scanf("%d", &in_.c[i]);
    for (int i = 0; i < m; ++i)
        scanf("%d%d", &in_.t[i], &in_.d[i]);
}

void _print_output()
{
    for (int i = 0; i < in_.m; ++i)
        printf("%lld\n", out_.ans[i]);
}

int main(int argc, char *argv[])
{
    _get_input();
    ford_1106b(in_, out_);
    _print_output();
    return 0;
}

