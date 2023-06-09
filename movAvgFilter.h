#ifndef MOVAVGFILTER
#define MOVAVGFILTER

#include <queue>

template<typename Scalar, size_t N>
class MovingAverageFilter
{
public:
    MovingAverageFilter() //Adding constructor to initialize private variable
    {
        sum = 0; //Using Constructor to initialize private sum variable to 0
    }

    Scalar Step(const Scalar& input)
    {
        //Add input to a sum variable that keeps track of the sum of elements inputted thus far
        sum += input;

        //Add input to queue keeping track of all elements
        vals.push(input);

        //Check if queue contains excess elements
        if (vals.size() > N)
        {
            sum -= vals.front();
            vals.pop();
        }

        //If Queue is Empty, average is 0 (check to prevent division by 0)
        if (vals.empty())
            return 0;

        //Return average of last N elements inputted
        return sum / N;
    }

private:
    std::queue<Scalar> vals; //Queue to keep track of last N elements inputted
    Scalar sum; //Using sum variable to track the sum of all elements added thus far
};

#endif
