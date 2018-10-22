#include "type.h"
#include <cstdio>

using namespace std;

_2018ICPC_NEERC_H_beros_in_t in_;
_2018ICPC_NEERC_H_beros_out_t out_;

static bool getq(char *s)
{
    int &q = in_.q;
    if (q > 0)
    {
        q --;
        scanf("%s", s);
        return true;
    }
    else
        return false;
}

static void putres(int cnt, const char *s)
{
    printf("%d ", cnt);
    if (cnt > 0) printf("%s\n", s);
    else printf("-\n");
}

void _get_input()
{
    int n;
    scanf("%d", &n);
    in_.n = n;
    for (int i = 0; i < n; ++i)
    {
        scanf("%s", in_.s[i]);
    }
    int q;
    scanf("%d", &q);
    in_.q = q;
    in_.getq = getq;
    in_.putres = putres;
}

void _print_output()
{
    // nil
}

int main(int argc, char *argv[])
{
    _get_input();
    beros_2018ICPC_NEERC_H(in_, out_);
    _print_output();
    return 0;
}
