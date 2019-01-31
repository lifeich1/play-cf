//-[
#include "type.h"
//-]
#include <queue>

namespace licf {
namespace wand_1106d {
    // placeholder
}
}

using namespace licf::wand_1106d;

int wand_1106d(const _in_t & in_, _out_t & out_)
{
    int n = in_.n;
    int *ans = out_.ans;
    ans[0] = 0;
    std::priority_queue<int, std::vector<int>, std::greater<int> > que;
    int *u = out_.u;
    for (int i = 0; i < n; ++i) u[i] = 0;
    u[0] = 1;
    for (int i = 0; i < n - 1; ++i)
    {
        int x = ans[i];
        for (unsigned int j = 0; j < in_.e[x].size(); ++j)
            if (!u[in_.e[x][j]])
            {
                int y = in_.e[x][j];
                u[y] = 1;
                que.push(y);
            }
        ans[i + 1] = que.top();
        que.pop();
    }
    return 0;
}


