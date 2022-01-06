#include <iostream>
#include <stack>

struct Node
{
    int data;
    Node *next;
};

int findLengthOfLoop(struct Node *loop_node)
{
    Node *iter = loop_node;
    int len = 1;

    while (iter->next != loop_node)
    {
        iter = iter->next;
        len++;
    }

    return len;
}

// print the list only after removal
void printList(struct Node *n)
{
    while (n != NULL)
    {
        std::cout << n->data << "->";
        n = n->next;
    }
    std::cout << "NULL" << std::endl;
}

struct Node *newNode(int data)
{
    struct Node *n = new Node();
    n->data = data;
    n->next = NULL;

    return n;
}

Node *reverseListUsingStack(Node *curr)
{
    std::stack<Node *> s;

    while (curr != NULL)
    {
        s.push(curr);
        curr = curr->next;
    }

    Node *head = curr = s.top();
    s.pop();
    while (!s.empty())
    {
        curr->next = s.top();
        s.pop();
        curr = curr->next;
    }
    curr->next = NULL;

    return head;
}

Node *reverseListIterative(Node *curr)
{
    Node *next = NULL;
    Node *prev = NULL;

    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;

        prev = curr;
        curr = next;
    }
    return prev;
}

Node *reverseListRecursive(Node *curr)
{
    // recursion break condition
    if (curr == NULL || curr->next == NULL)
    {
        return curr;
    }

    Node *headPtr = reverseListRecursive(curr->next);
    curr->next->next = curr;

    // Very tricky step, need to check the working mechanism with a list with 3 Nodes at least
    // 5->10->15
    curr->next = NULL;

    return headPtr;
}

Node *reverseListRecursive_simple(Node *prev, Node *curr)
{
    // recursion break condition
    if (curr == NULL || curr->next == NULL)
    {
        curr->next = prev;
        return curr;
    }

    Node *headPtr = reverseListRecursive_simple(curr, curr->next);
    curr->next = prev;
    return headPtr;
}

// Rotate the list from left by K Nodes
// List => 50->20->15->4->10 by k=3
// List after rotation => 4->10->50->20->15
void rotateListByLeft(Node **headPtr, int k)
{
    if (headPtr == NULL || *headPtr == NULL)
    {
        std::cout << "NULL Pointer passed";
        return;
    }

    Node *head = *headPtr;
    Node *temp = *headPtr;

    // Make it circular List
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = head;

    temp = head;
    while (k != 1)
    {
        k--;
        temp = temp->next;
    }

    *headPtr = temp->next;
    temp->next = NULL;
}

// Rotate the list from left by K Nodes
// List => 50->20->15->4->10 by k=3
// List after rotation => 15->4->10->50->20
void rotateListByRight(Node **headPtr, int k)
{
    Node *head = *headPtr;
}

// Driver Code
int main()
{
    struct Node *head = newNode(50);
    head->next = newNode(20);
    head->next->next = newNode(15);
    head->next->next->next = newNode(4);
    head->next->next->next->next = newNode(10);
    //   50->20->15->4->10

    // print the list
    std::cout << "Linked List\n";
    printList(head);

    std::cout << "Linked List after reversal \n";
    head = reverseListRecursive_simple(NULL, head);
    // head = reverseListRecursive(head);
    // head = reverseListIterative(head);
    // head = reverseListUsingStack(head);
    printList(head);

    std::cout << "Linked List after rotation by 4 \n";
    rotateListByLeft(&head, 4);
    printList(head);
    return 0;
}
