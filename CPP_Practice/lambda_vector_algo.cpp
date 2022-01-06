// C++ program to demonstrate lambda expression in C++
#include <vector>
#include <iostream>
#include <algorithm>
#include <numeric> // std::accumulate

using namespace std;

// Function to print vector
void printVector(std::vector<int> &v)
{
    std::for_each(v.begin(), v.end(), [](int a)
                  { std::cout << " " << a; });

    std::cout << std::endl;
}

int main()
{
    std::vector<int> v{4, 1, 3, 5, 2, 3, 1, 7};

    printVector(v);

    // below snippet find first number greater than 4
    // find_if searches for an element for which
    // function(third argument) returns true
    std::vector<int>::iterator p = std::find_if(v.begin(), v.end(), [](int a)
                                                { return (a > 4); });
    if (p != v.end())
        std::cout << "First number greater than 4 is : " << *p << std::endl;
    else
        std::cout << "Element not found" << std::endl;

    std::vector<int>::iterator p2 = std::find_if_not(v.begin(), v.end(), [](int a)
                                                     { return ((a % 2) == 0); });
    if (p2 != v.end())
        std::cout << "First odd number is : " << *p2 << std::endl;
    else
        std::cout << "Element not found" << std::endl;

    int count = 0;

    count = std::count_if(v.begin(), v.end(), [](int x)
                          { return x == 5; });
    if (count)
        std::cout << "Count of 5 is : " << count << std::endl;
    else
        std::cout << "5 not found in vector" << std::endl;

    std::cout << "Sorted Vector : " << std::endl;
    std::sort(v.begin(), v.end());
    printVector(v);

    // function for removing duplicate element (after sorting all
    // duplicate comes together)
    p = unique(v.begin(), v.end(), [](int a, int b)
               { return a == b; });

    // resizing vector to make size equal to total different number
    v.resize(distance(v.begin(), p));
    printVector(v);

    // accumulate function accumulate the container on the basis of
    // function provided as third argument
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int f = std::accumulate(arr, arr + 10, 1, [](int i, int j)
                            { return i * j; });

    cout << "Factorial of 10 is : " << f << endl;

    //     We can also access function by storing this into variable
    auto square = [](int i)
    {
        return i * i;
    };

    cout << "Square of 5 is : " << square(5) << endl;
}
