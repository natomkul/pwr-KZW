#pragma once

#include <iostream>
#include <vector>

class Opener
{
 protected:
    int len;
    std::vector<std::vector<int>> data;
    const char *fname;
 public:
    Opener(const char *fname);
    void print();
};
