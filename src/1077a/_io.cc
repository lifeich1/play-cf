//-[
#include "type.h"
//-]
#include <cstdio>

using namespace std;

_1077a_frgj_in_t in_;
_1077a_frgj_out_t out_ = {&in_};

static int tt;

static int getoneinp(int *a, int *b, int *k)
{
    if (tt)
    {
        tt--;
        scanf("%d%d%d", a, b, k);
        return 0;
    }
    else
        return -1;
}

static void putres(long long res)
{
    printf("%lld\n", res);
}

void _get_input()
{
    scanf("%d", &tt);
    in_.get = getoneinp;
    in_.put = putres;
}

void _print_output()
{
    // placeholder
}

int main(int argc, char *argv[])
{
    _get_input();
    frgj_1077a(in_, out_);
    _print_output();
    return 0;
}

