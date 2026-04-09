#include <iostream>
#include <vector>
#include "opener.h"
#include "123.h"
#include "sortSchrage.h"
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
 
    printf("\n123:\n ");
    printf( "1: %d \n ", cmax1);
    printf( "2: %d \n ", cmax2);
    printf( "3: %d \n ", cmax3);
    printf( "4: %d \n ", cmax4);

    printf( "sum: %d \n ", cmax1 + cmax2 + cmax3 + cmax4);


    int cmax1R = CmaxSortR(data1);
    int cmax2R = CmaxSortR(data2);
    int cmax3R = CmaxSortR(data3);
    int cmax4R = CmaxSortR(data4);
 
    printf("\nSortR:\n ");
    printf( "1: %d \n ", cmax1R);
    printf( "2: %d \n ", cmax2R);
    printf( "3: %d \n ", cmax3R);
    printf( "4: %d \n ", cmax4R);

    printf( "sum: %d \n ", cmax1R + cmax2R + cmax3R + cmax4R);

    printf("\nSchrage:\n ");
    int cmax1S = CmaxSchrage(data1);
    int cmax2S = CmaxSchrage(data2);
    int cmax3S = CmaxSchrage(data3);
    int cmax4S = CmaxSchrage(data4);
    
    printf( "1: %d \n ", cmax1S);
    printf( "2: %d \n ", cmax2S);
    printf( "3: %d \n ", cmax3S);
    printf( "4: %d \n ", cmax4S);

    printf( "sum: %d \n ", cmax1S + cmax2S + cmax3S + cmax4S);
}
