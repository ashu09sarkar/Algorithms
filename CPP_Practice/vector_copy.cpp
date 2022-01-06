#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to increment the value by 1
int increment(int x)
{
    return x + 1;
}

void usage_std_search(void)
{
    // Declaring the sequence to be searched into
    vector<int> v1 = {1, 2, 3, 4, 5, 6, 7};

    // Declaring the subsequence to be searched for
    vector<int> v2 = {3, 4, 5};

    // Declaring an iterator for storing the returning pointer
    vector<int>::iterator i1;

    // Using std::search and storing the result in
    // iterator i1
    i1 = std::search(v1.begin(), v1.end(), v2.begin(), v2.end());

    // checking if iterator i1 contains end pointer of v1 or not
    if (i1 != v1.end())
    {
        cout << "vector2 is present at index " << (i1 - v1.begin());
    }
    else
    {
        cout << "vector2 is not present in vector1";
    }
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int size = sizeof(arr) / sizeof(arr[0]);

    std::vector<int> vec1; //  Method 1
    for (auto a : arr)
    {
        vec1.push_back(a);
    }

    std::vector<int> vec2(arr, arr + size);      //  Method 2
    std::vector<int> vec3(begin(arr), end(arr)); //  Method 3

    std::vector<int> vec4;
    vec4.insert(vec4.begin(), begin(arr), end(arr)); //  Method 4

    std::vector<int> vec5;
    copy(begin(arr), end(arr), back_inserter(vec5)); //  Method 5

    std::vector<int> vec6;
    vec6.assign(arr, arr + size); //  Method 6
    // Assigns new contents to the vector, replacing its current
    // contents, and modifying its size accordingly.

    //////////////////// Method 7 : transform ///////////////////////////////////////////////
    // The std::transform() function takes 4 arguments, an iterator to the first element of the
    // array, an iterator to the last element of the array, the back_inserter function to insert
    // values from the back and a user-defined function which can be used to modify all the
    // elements of the array i.e, perform a unary operation, convert lower case characters to
    // upper case, etc.

    // Initialize an empty vector
    vector<int> vec7;

    // Copy the elements of the array into
    // vector v and increment each value
    transform(arr, arr + size, back_inserter(vec7), increment);

    /*
        for (int i = 0; i < size; i++)
        {
            vec.push_back(arr[i]);
        }
    */

    std::cout << std::endl;

    for (auto a : vec1)
    {
        std::cout << a << " ";
    }

    return 0;
}