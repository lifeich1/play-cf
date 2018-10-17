//-[
#include "type.h"
//-]

int bkq_1066c(const _1066c_bkq_in_t & in_, _1066c_bkq_out_t & out_)
{
    int op, id;
    int ls = 0, rs = 0, s = 0;
    while (in_.get(&op, &id)) 
    {
        switch (op) 
        {
            case 0: // L
                ls++; s++;
                out_.l[id] = -ls;
                out_.r[id] = s - 1 - rs;
                break;
            case 1: // R
                rs++; s++;
                out_.r[id] = -rs;
                out_.l[id] = s - 1 - ls;
                break;
            default: // query
            {
                int l = out_.l[id] + ls;
                int r = out_.r[id] + rs;
                out_.put(l < r ? l : r);
                break;
            }
        }
    }
    return 0;
}
