// C++ program to reverse a linked list using 
// 1. Using Two Pointers Interatively
// 2. Using Three Pointers Interatively
// 3. Using recusrion

#include <iostream>
using namespace std;
typedef uintptr_t ut;

/* Link list node */
struct Node {
	int data;
	struct Node* next;
};

// 1->2->3->4->NULL
/* 1. Function to reverse the linked list using Two Pointers Iteratively */
void reverseUsingTwoPtrs(struct Node** head_ref)
{
    struct Node* current = *head_ref;
    struct Node* prev = NULL;
    
    
    while(current->next != NULL)
    {
        *head_ref = current->next;
        current->next = prev;
        prev = current;
        current = *head_ref;
    }
    current->next = prev;
}

/* Function to push a node */
void push(struct Node** head_ref, int new_data)
{
	struct Node* new_node = new Node;
	new_node->data = new_data;
	new_node->next = (*head_ref);
	(*head_ref) = new_node;
}

/* 2. Function to reverse the linked list using Three Pointers Iteratively */
void reverseUsingThreePtrs(struct Node** head_ref)
{
    // Initialize current, previous and
    // next pointers
    Node* current = *head_ref;
    Node *prev = NULL, *next = NULL;
    
    while (current != NULL)
    {
        // Store next
        next = current->next;
        
        // Reverse current node's pointer
        current->next = prev;
        
        // Move pointers one position ahead.
        prev = current;
        current = next;
    }
    *head_ref = prev;
}

/* 3. Function to reverse the linked list Recursively */
struct Node* reverseRecursive(struct Node* head)
{
    if (head == NULL || head->next == NULL)
        return head;
        
    /* reverse the rest list and put the first element at the end */
    Node* rest = reverseRecursive(head->next);
    head->next->next = head;
    
    /* tricky step -- see the diagram */
    head->next = NULL;
    
    /* fix the head pointer */
    return rest;
}

/* Function to print linked list */
void printList(struct Node* head)
{
	struct Node* temp = head;
	while (temp != NULL) {
		printf("%d ", temp->data);
		temp = temp->next;
	}
}

/* Driver program to test above function*/
int main()
{
	/* Start with the empty list */
	struct Node* head = NULL;

	push(&head, 20);
	push(&head, 4);
	push(&head, 15);
	push(&head, 85);

	printf("Given linked list\n");
	printList(head);
	reverseUsingTwoPtrs(&head);
  // reverseUsingThreePtrs(&head);
  // head = reverseRecursive(head);
	printf("\nReversed Linked list \n");
	printList(head);
	return 0;
}
