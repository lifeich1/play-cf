#include "type.h"
#include <cstdio>

using namespace std;

_1066c_bkq_in_t in_;
_1066c_bkq_out_t out_;

static int q;

static bool getquery(int *op, int *id)
{
    //fprintf(stderr, "!%d ", q);
    if (q > 0)
    {
        q--;
        static char c[20];
        scanf("%s%d", c, id);
        //fprintf(stderr, "'%s' %d\n", c, *id);
        if (*c == 'L') *op = 0;
        else if (*c == 'R') *op = 1;
        else *op = 2;
        return true;
    }
    else
    {
        return false;
    }
}

static void putResult(int cnt)
{
    printf("%d\n", cnt);
}

void _get_input()
{
    scanf("%d", &q);
    in_.get = getquery;
    out_.put = putResult;
}

void _print_output()
{
    // pass
}

int main(int argc, char *argv[])
{
    _get_input();
    bkq_1066c(in_, out_);
    _print_output();
    return 0;
}
