#include "global.hpp"

int generateRandomNumber(int min, int max)
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dist(min,max);
    return dist(gen);
}