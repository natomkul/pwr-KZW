#pragma once

#include <iostream>
#include <vector>

struct Node
{
 public:
    int id;
    int X, Y;
    Node* prev;
    Node* next;
};

class Data
{
 private:
    int nodes_size = 100;
    std::vector<Node> nodes;

    int min_x = 0;
    int min_y = 0;

    int max_x = 0;
    int max_y = 0;
 
 public:
    Data(const char* file);
    void printData();

    int get_minX();
    int get_maxX();

    int get_minY();
    int get_maxY();

    std::vector<Node> get_nodes();
};
