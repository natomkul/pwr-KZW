#pragma once

#include <iostream>
#include <vector>

#include "job.h"

class Opener
{
 private:
    int len;
    std::vector<job> data;
    const char *fname;
 public:
    Opener(const char *fname);
    void print();

    int get_len();
    std::vector<job> get_data();
};

