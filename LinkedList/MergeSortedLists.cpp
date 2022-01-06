#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node *next;
};

void push(Node **head, int data)
{
    Node *new_node = new Node();
    new_node->data = data;
    new_node->next = NULL;

    if (*head == NULL) // No node present
    {
        *head = new_node;
        return;
    }

    Node *temp = *head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = new_node;
}

Node *SortedMergeRecursive(Node *a, Node *b)
{
    if (a == NULL)
        return b;

    if (b == NULL)
        return a;

    if (a->data <= b->data)
    {
        a->next = SortedMergeRecursive(a->next, b);
        return a;
    }
    else
    {
        b->next = SortedMergeRecursive(a, b->next);
        return b;
    }
}

Node *SortedMerge(Node *a, Node *b)
{
    Node *res = NULL;
    Node *temp = res;

    while (a != NULL && b != NULL)
    {
        if (a->data <= b->data)
        {
            if (res == NULL)
            {
                res = temp = a;
            }
            else
            {
                temp->next = a;
                temp = temp->next;
            }

            a = a->next;
        }
        else
        {
            if (res == NULL)
            {
                res = temp = b;
            }
            else
            {
                temp->next = b;
                temp = temp->next;
            }
            b = b->next;
        }
    }

    if (a)
    {
        temp->next = a;
    }

    if (b)
    {
        temp->next = b;
    }

    return res;
}

void printList(Node *head)
{
    while (head != NULL)
    {
        std::cout << head->data << "->";
        head = head->next;
    }
    std::cout << "NULL" << std::endl;
}

void frontAndBackSplit(Node *head, Node **frontRef, Node **backRef)
{
    Node *slowPtr = head;
    Node *fastPtr = head->next;

    while (fastPtr != NULL)
    {
        fastPtr = fastPtr->next;
        if (fastPtr != NULL)
        {
            slowPtr = slowPtr->next;
            fastPtr = fastPtr->next;
        }
    }

    *backRef = slowPtr->next;
    slowPtr->next = NULL;
    *frontRef = head;
}

void mergeSort(Node **headPtr)
{
    if ((*headPtr) == NULL || (*headPtr)->next == NULL) // Either no nodes or single node condition
        return;

    Node *frontRef = NULL;
    Node *backRef = NULL;

    frontAndBackSplit(*headPtr, &frontRef, &backRef);
    mergeSort(&frontRef);
    mergeSort(&backRef);
    *headPtr = SortedMerge(frontRef, backRef);
}

/* Driver program to test above functions*/
void mergeSort_driver()
{
    /* Start with the empty list */
    Node *res = NULL;
    Node *a = NULL;

    /* Let us create a unsorted linked lists to test the functions
Created lists shall be a: 2->3->20->5->10->15 */
    push(&a, 15);
    push(&a, 10);
    push(&a, 5);
    push(&a, 20);
    push(&a, 3);
    push(&a, 2);

    std::cout << "Calling Merge-Sort \n";
    /* Sort the above created Linked List */
    mergeSort(&a);

    std::cout << "Sorted Linked List is: \n";
    printList(a);

    return;
}

int main()
{
    /* Start with the empty list */
    Node *res = NULL;
    Node *a = NULL;
    Node *b = NULL;

    /* Let us create two sorted linked lists
    to test the functions
    Created lists, a: 5->10->15, b: 2->3->20 */

    push(&a, 5);
    push(&a, 10);
    push(&a, 15);
    printList(a);

    push(&b, 2);
    push(&b, 3);
    push(&b, 20);
    printList(b);
    /*
        // Remove duplicates from linked list
    res = SortedMerge(a, b);
    printList(res);
    * /

    /* Remove duplicates from linked list Recusrively*/
    res = SortedMergeRecursive(a, b);
    printList(res);

    mergeSort_driver();
    return 0;
}