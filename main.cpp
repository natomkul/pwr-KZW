#include <iostream>
#include <vector>
#include "opener.h"
#include "123.h"
int main()
{
    Opener *data1 = new Opener("data/data1.txt");
    Opener *data2 = new Opener("data/data2.txt");

    Opener *data3 = new Opener("data/data3.txt");
    Opener *data4 = new Opener("data/data4.txt");

    int cmax1 = Cmax123(data1);
    int cmax2 = Cmax123(data2);
    int cmax3 = Cmax123(data3);
    int cmax4 = Cmax123(data4);

    printf("cmax 1: %d \n", cmax1);
    printf("cmax 2: %d \n", cmax2);
    printf("cmax 3: %d \n", cmax3);
    printf("cmax 4: %d \n", cmax4);
    printf("sum: %d \n", cmax1 + cmax2 + cmax3 + cmax4);
}
