#include <iostream>

class Node
{
public:
    int data;
    Node *next;

    Node(int d) : data(d), next(nullptr)
    {
    }
};

class List
{
    Node *head;

public:
    List(Node *nodePtr = nullptr) : head(nodePtr)
    {
    }

    ~List()
    {

        // delete all node leaving head node
        while (head->next)
        {
            Node *temp = head->next->next;
            delete head->next;
            head->next = temp;
        }
        delete head;
    }

    void printMiddleOfLinkedList() const;
    void insertAtBack(int d);
    void print(void) const;
};

void List::printMiddleOfLinkedList() const
{
    if (head == nullptr)
    {
        std::cout << "printMiddleOfLinkedList: Empty Linked List" << std::endl;
        return;
    }

    Node *slow_P = head;
    Node *fast_P = head;
    while (fast_P != NULL && fast_P->next != NULL)
    {
        slow_P = slow_P->next;
        fast_P = head->next->next;
    }

    std::cout << "Middle of Linked List : " << slow_P->data << std::endl;
    return;
}

void List::insertAtBack(int d)
{
    if (head == nullptr)
    {
        head = new Node(d);
        return;
    }

    Node *currentNode = head;
    while (currentNode->next)
    {
        currentNode = currentNode->next;
    }
    currentNode->next = new Node(d);
}

void List::print(void) const
{
    if (head == nullptr)
    {
        std::cout << "Empty Linked List" << std::endl;
        return;
    }

    Node *currentNode = head;
    while (currentNode)
    {
        std::cout << currentNode->data << "->";
        currentNode = currentNode->next;
    }
    std::cout << std::endl;
}

int main()
{
    List *listP = new List();
    listP->insertAtBack(1);
    listP->insertAtBack(2);
    // listP->insertAtBack(3);
    // listP->insertAtBack(4);

    listP->print();
    listP->printMiddleOfLinkedList();

    return 0;
}