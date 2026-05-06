#include <iostream>
#include "PD.h"

int main()
{
    Opener* opener10 = new Opener("data/data2.txt");
    std::vector<job> data10 = opener10->get_data();
    int len10 = opener10->get_len();

    printf("Opd:\n");
    printf("data10:");
    PD_schedule(data10);
}

