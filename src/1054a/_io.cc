#include "type.h"
#include <cstdio>

using namespace std;

_1054a_elest_in_t in_;
_1054a_elest_out_t out_ = {&in_};

void _get_input()
{
    scanf("%d%d%d%d%d%d", &in_.x, &in_.y, &in_.z,
            &in_.t1, &in_.t2, &in_.t3);
}

void _print_output()
{
    printf(out_.flag ? "YES" : "NO");
    printf("\n");
}

int main(int argc, char *argv[])
{
    _get_input();
    elest_1054a(in_, out_);
    _print_output();
    return 0;
}
