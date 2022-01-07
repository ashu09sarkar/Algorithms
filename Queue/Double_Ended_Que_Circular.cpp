// C++ implementation of De-queue using circular array
// Perfectly working code

// init rear to : rear = capacity-1
// circular front and rear : rear = (rear + 1)%capacity
// rear = (capacity + rear - 1)%capacity

#include <iostream>
#include <climits>
using namespace std;

// Maximum size of array or Dequeue
#define MAX 100

// A structure to represent a Deque
class Deque
{
    int arr[MAX];
    int front;
    int rear;
    int size;
    int capacity;

public:
    Deque(int num)
    {
        front = -1;
        capacity = num;
        rear = capacity - 1;
        this->size = 0;
    }

    // Operations on Deque:
    void insertfront(int key);
    void insertrear(int key);
    void deletefront();
    void deleterear();
    bool isFull();
    bool isEmpty();
    int getFront();
    int getRear();
};

void Deque::insertfront(int key)
{
    if (isFull())
    {
        std::cout << "Stack Overflow" << std::endl;
        return;
    }

    // if we are going to insert first element
    if (front == -1 && rear == (capacity - 1))
    {
        std::cout << "Empty Queue Found, Inserting first element \n";
        front = 0;
        rear = 0;
    }
    else
    {
        front = (capacity + front - 1) % capacity;
    }
    arr[front] = key;
    size++;
    std::cout << "Inserted " << arr[front] << " at Front here front = : " << front << " with rear = " << rear << " size = " << size << std::endl;
}

void Deque::insertrear(int key)
{
    if (isFull())
    {
        std::cout << "Stack Overflow" << std::endl;
        return;
    }
    // if we are going to insert first element
    if ((front == -1) && (rear == (capacity - 1)))
    {
        std::cout << "Empty Queue Found, Inserting first element \n";
        front = 0;
    }

    rear = (rear + 1) % capacity;
    arr[rear] = key;
    size++;
    std::cout << "Inserted " << arr[rear] << " at rear here  front = : "
              << front << " with rear = " << rear << " size = " << size << std::endl;
}

void Deque::deletefront()
{
    if (isEmpty())
    {
        std::cout << "Stack Underflow" << std::endl;
        return;
    }

    std::cout << "Going to delete " << arr[front] << " from Front here front = " << front << " with rear = " << rear << " size = " << size << std::endl;
    // if we are going to delete last element
    if (front == rear)
    {
        front = -1;
        rear = capacity - 1;
        std::cout << "We are going to delete last element in queue \n";
    }
    else
    {
        front = (front + 1) % capacity;
    }
    size--;
    std::cout << "After deleting from Front, here front = " << front << " with rear = " << rear << " size = " << size << std::endl;
}

void Deque::deleterear()
{
    if (isEmpty())
    {
        std::cout << "Stack Underflow" << std::endl;
        return;
    }

    std::cout << "Going to delete " << arr[rear] << " from rear here front = " << front << " with rear = " << rear << " size = " << size << std::endl;
    // if we are going to delete last element
    if (front == rear)
    {
        std::cout << "We are going to delete last element in queue \n";
        front = -1;
        rear = capacity - 1;
    }
    else
    {
        rear = (capacity + rear - 1) % capacity;
    }
    size--;
    std::cout << "After deleting from rear, here front = " << front << " with rear = " << rear << " size = " << size << std::endl;
}

bool Deque::isFull()
{
    return (front == (rear + 1) % capacity);
}

bool Deque::isEmpty()
{
    return (front == -1);
}

int Deque::getFront()
{
    if (isEmpty())
    {
        std::cout << "Stack Underflow" << std::endl;
        return INT_MIN;
    }
    return arr[front];
}

int Deque::getRear()
{
    if (isEmpty())
    {
        std::cout << "Stack Underflow" << std::endl;
        return INT_MIN;
    }
    return arr[rear];
}

// Driver program to test above function
int main()
{
    Deque dq(5);
    cout << "Insert element at rear end : 5 \n";
    dq.insertrear(5);

    cout << "insert element at rear end : 10 \n";
    dq.insertrear(10);

    cout << "get rear element "
         << " "
         << dq.getRear() << endl;

    dq.deleterear();
    cout << "After delete rear element new rear"
         << " become " << dq.getRear() << endl;

    cout << "inserting element at front end \n";
    dq.insertfront(15);

    cout << "get front element "
         << " "
         << dq.getFront() << endl;

    dq.deletefront();

    cout << "After delete front element new "
         << "front become " << dq.getFront() << endl;
    return 0;
}
