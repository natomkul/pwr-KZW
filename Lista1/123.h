#include <algorithm>
#include "opener.h"

int Cmax123(Opener *op)
{
    int size = op->get_len();
    std::vector<std::vector<int>> RPQ = op->get_data();

    int t = 0;
    int Cmax = 0;

    for (int i = 0; i < size; i++)
    {
        t = std::max(t, RPQ[i][0]);
        t += RPQ[i][1];

        Cmax = std::max(Cmax, t + RPQ[i][2]);
    }

    return Cmax;
}
