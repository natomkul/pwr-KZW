#include <utility>
#include "opener.h"
#include "sortR.h"

int maxQ(std::vector<std::vector<int>> &RPQ)
{
    int max_index = 0;
    int max_value = RPQ[0][2];

    for (size_t i = 1; i < RPQ.size(); i++)
    {
        if (RPQ[i][2] > max_value)
        {
            max_value = RPQ[i][2];
            max_index = i;
        }
    }

    return max_index;
}

int CmaxSchrage(Opener *op)
{
    std::vector<std::vector<int>> N = sortR(op);
    std::vector<std::vector<int>> G;
    std::vector<std::vector<int>> RPQ;

    int t = 0;
    int Cmax = 0;
    std::vector<int> temp;

    while (!G.empty() || !N.empty())
    {
        temp = N[0];

        while (!N.empty() && N[0][0] <= t)
        {
            G.push_back(N[0]);
            N.erase(N.begin());
        }

        if (!G.empty())
        {
            int idx = maxQ(G);

            t = std::max(t, G[idx][0]);
            t += G[idx][1];
            Cmax = std::max(Cmax, t + G[idx][2]);

            G.erase(G.begin() + idx);

        } else {
            t = N[0][0];
        }
    }

    return Cmax;
}

