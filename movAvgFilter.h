#ifndef MOVAVGFILTER
#define MOVAVGFILTER

#include <iostream>
#include <queue>

template<typename Scalar, size_t N>
class MovingAverageFilter
{
public:
    MovingAverageFilter(); //Adding constructor to initialize private variable
    Scalar Step(const Scalar& input);
private:
    std::queue<Scalar> vals; //Queue to keep track of last N elements inputted
    Scalar sum; //Using sum variable to track the sum of all elements added thus far
};

#endif