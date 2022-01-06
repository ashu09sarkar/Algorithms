#include <iostream>

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

void removeLoop(struct Node *loop_node, struct Node *head)
{
    Node *iter = head;
    // find length of loop
    int k = findLengthOfLoop(loop_node);
    std::cout << "Length of the loop is : " << k << std::endl;

    while (k != 1)
    {
        iter = iter->next;
        k--;
    }

    while (iter->next != head)
    {
        head = head->next;
        iter = iter->next;
    }

    iter->next = NULL;
}

void detectAndRemoveLoop(struct Node *head)
{
    struct Node *slow_p = head;
    struct Node *fast_p = head;

    while (fast_p != NULL)
    {
        fast_p = fast_p->next;
        if (fast_p != NULL)
        {
            slow_p = slow_p->next;
            fast_p = fast_p->next;
        }

        if (slow_p == fast_p)
        {
            std::cout << "Loop Found" << std::endl;
            removeLoop(slow_p, head);
            return;
        }
    }
    std::cout << "Loop Not Found" << std::endl;
}

// print the list only after removal
void printList(struct Node *n)
{
    while (n != NULL)
    {
        std::cout << n->data << "->";
        n = n->next;
    }
    std::cout << std::endl;
}

struct Node *newNode(int data)
{
    struct Node *n = new Node();
    n->data = data;
    n->next = NULL;

    return n;
}

Node *reverseList(Node *prev, Node *curr)
{
    // recursion break condition
    if (curr == NULL || curr->next == NULL)
    {
        curr->next = prev;
        return curr;
    }

    Node *headPtr = reverseList(curr, curr->next);
    curr->next = prev;
    return headPtr;
}

// Driver Code
int main()
{
    struct Node *head = newNode(50);
    // head->next = head;

    head->next = newNode(20);
    // head->next->next = head;
    head->next->next = newNode(15);
    head->next->next->next = newNode(4);
    head->next->next->next->next = newNode(10);
    // 50->20->15->4->10
    /* Create a loop for testing */
    head->next->next->next->next->next = head->next->next;
    //  50->20->15->4->10--]
    //           ^         |
    //           |---------]

    detectAndRemoveLoop(head);

    // print the list only after removal
    std::cout << "Linked List after removing loop \n";
    printList(head);

    std::cout << "Linked List after reversal \n";
    head = reverseList(NULL, head);
    printList(head);
    return 0;
}
