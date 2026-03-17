#include <iostream>
#include "opener.h"

Opener::Opener(const char *fname) : fname(fname)
{
    FILE *fp = fopen(fname, "r");
    if (fp == NULL) 
    {
        printf("Blad otwarcia pliku\n");
        return;
    }

    fscanf(fp, "%d", &len);

    data.resize(len, std::vector<int>(3));

    for (int i = 0; i < len; i++) 
    {
        for (int j = 0; j < 3; j++) 
        {
            fscanf(fp, "%d", &data[i][j]);
        }
    }

    fclose(fp);
}

void Opener::print()
{
    for (int i = 0; i < len; i++) 
    {
        for (int j = 0; j < 3; j++) 
        {
            printf("%d ", data[i][j]);
        }
        printf("\n");
    }
}
