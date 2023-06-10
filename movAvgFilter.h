#pragma once

#include <queue>

template<typename Scalar, size_t N>
class MovingAverageFilter
{
public:
    MovingAverageFilter() : sum(0), arrSize(0), oldInd(0) {} //Adding constructor to initialize private variable

    Scalar Step(const Scalar& input)
    {
        //Add input to a sum variable that keeps track of the sum of elements inputted thus far
        sum += input;

        if(arrSize == N) //Check if array is max size
        {
            sum -= vals[oldInd]; //Replace oldest element with newest one
            vals[oldInd] = input;
            if(oldInd == N - 1) //If the index of the oldest element is the last element in array, loop back to 0
                oldInd = 0;
            else
                oldInd++;
        }
        else //Array is still not max size
        {
            vals[arrSize] = input;
            arrSize++;
        }

        //Return average of last N elements inputted
        return sum / N;
    }

private:
    Scalar vals [N]; //Queue to keep track of last N elements inputted
    int arrSize; //Variable to keep track of number of elements in array
    int oldInd; //Variable to keep track of index of oldest element in array
    Scalar sum; //Using sum variable to track the sum of all elements added thus far
};