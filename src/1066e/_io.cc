#include "type.h"
#include <cstdio>

const int N = 200100;
char a[N], b[N];

int main(int argc, char *argv[])
{
    int n, m;
    scanf("%d%d%s%s", &n, &m, a, b);
    printf("%d\n", bnas_1066e(n, a, m, b));
    return 0;
}
