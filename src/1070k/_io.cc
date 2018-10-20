#include "type.h"
#include <cstdio>

using namespace std;

_2018ICPC_NEERC_K_vpst_in_t in_;
_2018ICPC_NEERC_K_vpst_out_t out_;

void _get_input()
{
    int n, k;
    scanf("%d%d\n", &n, &k);
    in_.n = n;
    in_.k = k;
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", in_.a + i);
    }
}

void _print_output()
{
    if (out_.flag)
    {
        printf("Yes\n");
        for (int i = 0; i < in_.k; ++i)
        {
            printf("%d ", out_.res[i]);
        }
        printf("\n");
    }
    else
    {
        printf("No\n");
    }
}

int main(int argc, char *argv[])
{
    _get_input();
    vpst_2018ICPC_NEERC_K(in_, out_);
    _print_output();
    return 0;
}
