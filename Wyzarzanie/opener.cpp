#include "opener.h"

Data::Data(const char* file)
{
    FILE *fp = fopen(file, "r");
    if (fp == NULL) 
    {
        printf("Blad otwarcia pliku\n");
        return;
    }

    for (int i = 0; i < nodes_size; i++) 
    {
        Node temp;
        fscanf(fp, "%d %d %d", &temp.id, &temp.X, &temp.Y);
    
        min_x = std::min(temp.X, min_x);
        min_y = std::min(temp.Y, min_y);
 
        max_x = std::max(temp.X, max_x);
        max_y = std::max(temp.Y, max_y);

        nodes.push_back(temp);
    }

    for (int i = 0; i < nodes_size; i++) 
    {
 
        if (i > 0)
        {
            nodes[i].prev = &nodes[i - 1];
        } else {
            nodes[i].prev = &nodes[nodes_size - 1];
        }

        if (i < nodes_size - 1)
        {
            nodes[i].next = &nodes[i + 1];
        } else {
            nodes[i].next = &nodes[0];
        }
    }

    fclose(fp);
}

void Data::printData()
{
    for (int i = 0; i < nodes_size; i++) 
    {
        printf("indx: %d  ", i);
        printf("id: %d  ", nodes[i].id);
        printf("X: %d  ", nodes[i].X);
        printf("Y: %d\n", nodes[i].Y);
        printf("prev: %d   next: %d\n", nodes[i].prev->id, nodes[i].next->id);
    }
}

int Data::get_minX()
{
    return min_x;
}

int Data::get_maxX()
{
    return max_x;
}

int Data::get_minY()
{
    return min_y;
}

int Data::get_maxY()
{
    return max_y;
}

std::vector<Node> Data::get_nodes()
{
    return nodes;
}

