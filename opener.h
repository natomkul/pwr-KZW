#pragma once

#include <iostream>
#include <vector>

class Opener
{
 private:
    int len;
    std::vector<std::vector<int>> data;
    const char *fname;
 public:
    Opener(const char *fname);
    void print();

    int get_len();
    std::vector<std::vector<int>> get_data();
};
