#include "movAvgFilter.h"
#include <iostream>
#include <queue>
using namespace std;

template<typename Scalar, size_t N>
MovingAverageFilter<Scalar, N>::MovingAverageFilter()
{
    sum = 0; //Using Constructor to initialize private sum variable to 0
}


template<typename Scalar, size_t N>
Scalar MovingAverageFilter<Scalar, N>::Step(const Scalar& input)
{
    //Add input to a sum variable that keeps track of the sum of elements inputted thus far
    sum += input;

    //Add input to queue keeping track of all elements
    vals.push(input);

    //Check if queue contains excess elements
    if(vals.size() > N)
    {
        sum -= vals.front();
        vals.pop();
    }

    //If Queue is Empty, average is 0 (check to prevent division by 0)
    if(vals.empty())
        return 0;

    //Return average of last N elements inputted
    return sum / vals.size();
}


int main()
{
    MovingAverageFilter<double, 2> mov; //Initialize Filter to take average of last 2 elements and return average as double
    cout << "Enter in Number to be Added to Filter (Enter -1 to quit program): "<<endl;
    double input;
    cin >> input;

    while (!cin)
    {
        cout << "Please Enter Valid Number (Enter -1 to quit program): "<<endl;
        cin.clear();
        cin.ignore();
        cin >> input;
    }

    while(input != -1)
    {
        cout<< "The Current Step Average is: " << mov.Step(input) <<endl <<endl;
        cout << "Enter in Number to be Added to Filter (Enter -1 to quit program): "<<endl;
        cin >> input;
        while (!cin)
        {
            cout << "Please Enter Valid Number (Enter -1 to quit program): "<<endl;
            cin.clear();
            cin.ignore();
            cin >> input;
        }
    }
}