#include "opener.h"

class Anealling
{
 private:
    double temperature;

    std::vector<std::shared_ptr<Node>> current;
    double Lcurrent;

    std::vector<std::shared_ptr<Node>> best;
    double Lbest;

    double pathL(const std::vector<std::shared_ptr<Node>>& nodes);
    //std::vector<Node> try_new();

 public:
    Anealling(std::vector<std::shared_ptr<Node>> current, int temperature);
    
    std::vector<std::shared_ptr<Node>> try_new();
};
