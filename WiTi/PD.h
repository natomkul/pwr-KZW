#include "opener.h"
#include <climits>
#include <algorithm>

void PD_schedule(std::vector<job>& jobs)
{
    int n = jobs.size();
    int SIZE = 1 << n;

    std::vector<int> C(SIZE, 0);
    std::vector<int> F(SIZE, INT_MAX);
    std::vector<int> parent(SIZE, -1);

    for (int mask = 1; mask < SIZE; mask++)
    {
        for (int i = 0; i < n; i++)
        {
            if (mask & (1 << i))
                C[mask] += jobs[i].P;
        }
    }

    F[0] = 0;

    for (int mask = 1; mask < SIZE; mask++)
    {
        for (int i = 0; i < n; i++)
        {
            if (mask & (1 << i))
            {
                int prev = mask ^ (1 << i);

                int tardiness = std::max(0, C[mask] - jobs[i].D);
                int cost = jobs[i].W * tardiness;

                if (F[prev] != INT_MAX && F[prev] + cost < F[mask])
                {
                    F[mask] = F[prev] + cost;
                    parent[mask] = i;
                }
            }
        }
    }

    int mask = SIZE - 1;
    std::vector<int> order;

    while (mask)
    {
        int i = parent[mask];
        order.push_back(jobs[i].I);
        mask ^= (1 << i);
    }

    std::reverse(order.begin(), order.end());

    std::cout << "Minimalna kara: " << F[SIZE - 1] << "\n";
    std::cout << "Kolejnosc: ";

    for (int x : order)
        std::cout << x << " ";

    std::cout << "\n";
}
