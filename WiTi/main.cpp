#include <iostream>
#include "PD.h"

int main()
{
    Opener* opener10 = new Opener("data/data1.txt");
    std::vector<job> data10 = opener10->get_data();
    int len10 = opener10->get_len();

    printf("data10: ");
    PD_schedule(data10);

    Opener* opener11 = new Opener("data/data2.txt");
    std::vector<job> data11 = opener11->get_data();
    int len11 = opener11->get_len();

    printf("\n");
    printf("data11: ");
    PD_schedule(data11);

    Opener* opener12 = new Opener("data/data3.txt");
    std::vector<job> data12 = opener12->get_data();
    int len12 = opener12->get_len();

    printf("\n");
    printf("data12: ");
    PD_schedule(data12);

    Opener* opener13 = new Opener("data/data4.txt");
    std::vector<job> data13 = opener13->get_data();
    int len13 = opener13->get_len();

    printf("\n");
    printf("data13: ");
    PD_schedule(data13);

    Opener* opener14 = new Opener("data/data5.txt");
    std::vector<job> data14 = opener14->get_data();
    int len14 = opener14->get_len();

    printf("\n");
    printf("data14: ");
    PD_schedule(data14);

    Opener* opener15 = new Opener("data/data6.txt");
    std::vector<job> data15 = opener15->get_data();
    int len15 = opener15->get_len();

    printf("\n");
    printf("data15: ");
    PD_schedule(data15);

    Opener* opener16 = new Opener("data/data7.txt");
    std::vector<job> data16 = opener16->get_data();
    int len16 = opener16->get_len();

    printf("\n");
    printf("data16: ");
    PD_schedule(data16);

    Opener* opener17 = new Opener("data/data8.txt");
    std::vector<job> data17 = opener17->get_data();
    int len17 = opener17->get_len();

    printf("\n");
    printf("data17: ");
    PD_schedule(data17);

    Opener* opener18 = new Opener("data/data9.txt");
    std::vector<job> data18 = opener18->get_data();
    int len18 = opener18->get_len();

    printf("\n");
    printf("data18: ");
    PD_schedule(data18);

    Opener* opener19 = new Opener("data/data10.txt");
    std::vector<job> data19 = opener19->get_data();
    int len19 = opener19->get_len();

    printf("\n");
    printf("data19: ");
    PD_schedule(data19);

    Opener* opener20 = new Opener("data/data11.txt");
    std::vector<job> data20 = opener20->get_data();
    int len20 = opener20->get_len();

    printf("\n");
    printf("data20: ");
    PD_schedule(data20);
}

