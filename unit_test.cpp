#include "movAvgFilter.h"
#include <iostream>

int main()
{
    
    MovingAverageFilter<float, 2> mov; //Initialize Filter to take average of last 2 elements and return average as double
    std::cout << "Enter in Number to be Added to Filter (Enter -1 to quit program): "<< std::endl;
    double input;
    std::cin >> input;

    while (!std::cin)
    {
        std::cout << "Please Enter Valid Number (Enter -1 to quit program): "<< std::endl;
        std::cin.clear();
        std::cin.ignore();
        std::cin >> input;
    }

    while(input != -1)
    {
        std::cout << "The Current Step Average is: " << mov.Step(input) << std::endl << std::endl;
        std::cout << "Enter in Number to be Added to Filter (Enter -1 to quit program): "<< std::endl;
        std::cin >> input;
        while (!std::cin)
        {
            std::cout << "Please Enter Valid Number (Enter -1 to quit program): "<< std::endl;
            std::cin.clear();
            std::cin.ignore();
            std::cin >> input;
        }
    }
}