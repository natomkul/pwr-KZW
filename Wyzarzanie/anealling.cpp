#include "anealling.h"

Anealling::Anealling(std::vector<std::shared_ptr<Node>> current, int temperature) : current(current), 
                                                                   temperature(temperature)
{
    Lcurrent = pathL(current);

    best = current;
    Lbest = Lcurrent;
}

double Anealling::pathL(const std::vector<std::shared_ptr<Node>>& nodes)
{
    double len = 0;

    for (int i = 0; i < (nodes_size - 1); i++)
    {
        len += sqrt(pow(nodes[i]->X - nodes[i + 1]->X, 2) + pow(nodes[i]->Y - nodes[i + 1]->Y, 2));
    }

    len+= sqrt(pow(nodes[nodes_size - 1]->X - nodes[0]->X, 2) + pow(nodes[nodes_size - 1]->Y - nodes[0]->Y, 2));

    return len;
}

std::vector<std::shared_ptr<Node>> Anealling::try_new()
{
    auto newPath = current;

    int i = rand() % nodes_size;
    int j = rand() % nodes_size;

    //printf("i: %d,  index: %d, next id: %d, prev id: %d\n", i, newPath[i]->id, newPath[i]->next->id, newPath[i]->prev->id);
    //printf("j: %d,  index: %d, next id: %d, prev id: %d\n", j, newPath[j]->id, newPath[j]->next->id, newPath[j]->prev->id);
   
    std::swap(newPath[i], newPath[j]);

    //printf("i: %d,  index: %d, next id: %d, prev id: %d\n", i, newPath[i]->id, newPath[i]->next->id, newPath[i]->prev->id);
    //printf("j: %d,  index: %d, next id: %d, prev id: %d\n", j, newPath[j]->id, newPath[j]->next->id, newPath[j]->prev->id);

    double Lnew = pathL(newPath);

    printf("current L: %f\n", Lcurrent);
    //printf("new L: %f\n", Lnew);

    if (Lnew < Lbest)
    {
        best = newPath;
        Lbest = Lnew;

        current = newPath;
        Lcurrent = Lnew;

    } else if (Lnew < Lcurrent) {

        current = newPath;
        Lcurrent = Lnew;
        
    } else {

        double diff = Lnew - Lcurrent;
        double prob = exp(-(diff) / temperature);
        double randV = (double)rand() / RAND_MAX;

        //printf("diff: %f\nP: %f\nrandV: %f\n", diff, prob, randV);

        if (randV < prob)
        {
            current = newPath;
            Lcurrent = Lnew;
        }
    }
        
    temperature *= 0.998;
    double t = std::max(temperature, 0.0001);

    return current;
}

