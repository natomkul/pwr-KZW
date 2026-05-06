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

    data.resize(len);

    for (int i = 0; i < len; i++) 
    {
        fscanf(fp, "%d %d %d", &data[i].P, &data[i].W, &data[i].D);
       data[i].I = i;
    }

    fclose(fp);
}

void Opener::print()
{
    for (int i = 0; i < len; i++)
    {
        printf("Job: %d ", data[i].I);
        printf("%d ", data[i].P);
        printf("%d ", data[i].W);
        printf("%d \n", data[i].D);
    }
}

int Opener::get_len()
{
    return len;
}

std::vector<job> Opener::get_data()
{
    return data;
}


