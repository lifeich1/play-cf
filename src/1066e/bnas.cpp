#define MOD 998244353

int bnas_1066e(const int n, const char *a, const int m, const char *b)
{
    int ret = 0;
    for (int i = 0, c = 0; i < m; ++i)
    {
        if (b[i] == '1') c++;
        ret = (ret << 1) % MOD;
        int j = n - m + i;
        if (j >= 0 && a[j] == '1')
        {
            ret = (ret + c) % MOD;
        }
    }
    return ret;
}

#undef MOD
