#include <iostream>
#include <stack>

struct Node
{
    int data;
    Node *next;

    Node(int key) : data(key), next(NULL) {}
};

Node *push(Node **head_ptr, int key)
{
    if (head_ptr == NULL)
        return NULL;

    Node *new_node = new Node(key);
    new_node->next = *head_ptr;
    *head_ptr = new_node;

    return *head_ptr;
}

int lengthOfList_Recusrive(Node *head)
{
    if (head == NULL)
        return 0;

    return 1 + lengthOfList_Recusrive(head->next);
}

void printList(Node *head)
{
    std::cout << "Printing the list : ";

    while (head)
    {
        std::cout << head->data << "->";
        head = head->next;
    }

    std::cout << std::endl;
}

Node *reverseListUsingStack(Node *head)
{
    Node *curr = head;
    std::stack<Node *> st;

    while (curr)
    {
        st.push(curr);
        curr = curr->next;
    }

    if (!st.empty())
    {
        head = curr = st.top();
        st.pop();
    }

    while (!st.empty())
    {
        curr->next = st.top();
        st.pop();
        curr = curr->next;
    }

    curr->next = NULL;
    return head;
}

Node *reverseListRecursive(Node *head)
{
    // reach to the end of the list and roll back from there
    // recursion break condition
    if (head == NULL || head->next == NULL)
        return head;

    // recusrive call
    Node *ret = reverseListRecursive(head->next);

    // core operation
    head->next->next = head;
    head->next = NULL;

    return ret;
}

Node *reverseListRecursive_Simple(Node *prev, Node *curr)
{
    // reach to the end of the list and roll back from there
    // recursion break condition
    if (curr == NULL)
        return prev;

    // recusrive call
    Node *ret = reverseListRecursive_Simple(curr, curr->next);

    // core operation
    curr->next = prev;
    return ret;
}

Node *reverseListIterative(Node *curr)
{
    Node *prev = NULL;
    Node *next = NULL;

    while (curr)
    {
        next = curr->next;
        curr->next = prev;

        prev = curr;
        curr = next;
    }

    return prev;
}

// In Progress
// Rotate the list from right by K Nodes
// List => 50->20->15->4->10->5 by k=2
// List after rotation => 10->5->50->20->15->4
Node *rotateListByRight(Node *head, int k)
{

    // 1. reverse last k nodes
    // 2. reverse remaining nodes in front
    // 3. reverse the resultant list

    // 1. reverse last k nodes
    Node *prev = NULL;
    Node *next = NULL;
    Node *curr = head;
    while (curr && k > 0)
    {
        next = curr->next;
        curr->next = prev;

        prev = curr;
        curr = next;
        k--;
    }

    // 2. reverse remaining nodes in front
    head->next = reverseListIterative(curr);
    // 3. reverse the resultant list
    head = reverseListIterative(prev);
    return head;
}

// Rotate the list from left by K Nodes
// List => 50->20->15->4->10 by k=3
// List after rotation => 4->10->50->20->15
void rotateListByLeft_CircluarListMethod(Node **headPtr, int k)
{
    // This method automatically takes care of the case,
    // when k is greater than size of list
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

// This method is essentially array-rotation technique
// Rotate the list from left by K Nodes
// List => 50->20->15->4->10->5 by k=3
// List after rotation => 4->10->5->50->20->15
Node *rotateListByLeft_ArrayRoationMethod(Node *head, int k)
{
    // TODO : take care of the case, when k is greater than size of list
    // 1. reverse first k nodes
    // 2. reverse remaining nodes
    // 3. reverse the resultant list

    // 1. reverse first k nodes
    Node *prev = NULL;
    Node *next = NULL;
    Node *curr = head;
    while (curr && k > 0)
    {
        next = curr->next;
        curr->next = prev;

        prev = curr;
        curr = next;
        k--;
    }

    // 2. reverse remaining nodes
    head->next = reverseListIterative(curr);
    // 3. reverse the resultant list
    head = reverseListIterative(prev);
    return head;
}

Node *reverseList_inBlocks(Node *head, int size)
{
    if (head == NULL)
        return NULL;

    // 1. reverse k nodes
    Node *prev = NULL;
    Node *next = NULL;
    Node *curr = head;

    int count = size;
    while (curr && count > 0)
    {
        next = curr->next;
        curr->next = prev;

        prev = curr;
        curr = next;
        count--;
    }

    // 2. reverse remaining nodes recursively
    head->next = reverseList_inBlocks(curr, size);

    return prev;
}
int main(void)
{
    Node *root = new Node(5);

    push(&root, 10);
    push(&root, 4);
    push(&root, 15);
    push(&root, 20);
    push(&root, 50);
    //   50->20->15->4->10->5

    printList(root);

    root = reverseListIterative(root);
    std::cout << "Reversed the list using iterative method: ";
    printList(root);

    root = reverseListRecursive(root);
    std::cout << "Reversed the list using recursive method: ";
    printList(root);

    root = reverseListRecursive_Simple(NULL, root);
    std::cout << "Reversed the list using recursive-simple method: ";
    printList(root);

    root = reverseListUsingStack(root);
    std::cout << "Reversed the list using stack method: ";
    printList(root);

    root = rotateListByLeft_ArrayRoationMethod(root, 3);
    std::cout << "Rotate the list to left by 3 nodes: ";
    printList(root);

    root = reverseList_inBlocks(root, 2);
    std::cout << "Rotate the list in blocks of 2 : ";
    printList(root);

    root = reverseList_inBlocks(root, 3);
    std::cout << "Rotate the list in blocks of 3 : ";
    printList(root);

    int length = lengthOfList_Recusrive(root);
    std::cout << "Length of list is : " << length << std::endl;
}