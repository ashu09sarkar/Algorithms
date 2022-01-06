// C++ Stack Implemention, using array

#include <stdio.h>
#include <iostream>

#define MAX 1000

using namespace std;

class Stack
{
    int topIndex;
    int arr[MAX];

public:
    Stack() { topIndex = -1; }
    int pop();
    int top();
    bool push(int data);
    bool isEmpty();
};

int Stack::pop()
{
}

int Stack::top()
{
}

bool Stack::push(int data)
{
    if (topIndex < MAX - 1)
    {
        std::cout << "data pushed to stack : " << data << std::endl;

        arr[++topIndex] = data;
        return true;
    }
    else
    {
        std::cout << "stack overflow" << std::endl;
        return false;
    }
}

bool Stack::isEmpty()
{
    return (topIndex < 0);
}

int main()
{
    return 0;
}