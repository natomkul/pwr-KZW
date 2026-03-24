#include "opener.h"

std::vector<std::vector<int>> sortR(Opener *op) 
{
    int size = op->get_len();
    std::vector<std::vector<int>> RPQ = op->get_data();

    for (int i = 0; i < size - 1; i++) 
    {
        bool swapped = false;

        for (int j = 0; j < size - 1 - i; j++) 
        {
            if (RPQ[j][0] > RPQ[j + 1][0]) 
            {
                std::vector<int> temp = RPQ[j];
                RPQ[j] = RPQ[j + 1];
                RPQ[j + 1] = temp;
                swapped = true;
            }
        }

        if (!swapped) break;
    }

    return RPQ;
}

int CmaxSortR(Opener *op)
{
    std::vector<std::vector<int>> RPQ = sortR(op);
    int size = op->get_len();

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
