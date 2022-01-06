// Stack Using a Linked List Implementation

#include <iostream>

#define STACK_MIN_DATA -1

struct StackNode
{
    int data;
    struct StackNode *next;
};

struct Stack
{
    int capacity;
    int top;
    struct StackNode *stackHead;
};

struct Stack *createStack(int capacity)
{
    struct Stack *st = (struct Stack *)malloc(sizeof(struct Stack));
    st->capacity = capacity;
    st->top = 0;
    st->stackHead = NULL;

    return st;
}

void push(struct Stack *st, int data)
{
    if (st->top < st->capacity)
    {
        struct StackNode *stNewNode = (struct StackNode *)malloc(sizeof(struct StackNode));
        stNewNode->data = data;
        stNewNode->next = st->stackHead;
        st->stackHead = stNewNode;
        st->top++;
    }
    else
    {
        std::cout << "Stack Overflow Condition Reached" << std::endl;
    }
}

void pop(struct Stack *st)
{
    if (st->top > 0)
    {
        struct StackNode *poppedNode = st->stackHead;
        st->stackHead = st->stackHead->next;
        st->top--;
        free(poppedNode);
        return;
    }
    else
    {
        std::cout << "Stack Empty(Underflow) Condition Reached" << std::endl;
        return;
    }
}

int top(struct Stack *st)
{
    if (st->top > 0)
    {
        return st->stackHead->data;
    }
    else
    {
        return STACK_MIN_DATA;
    }
}

int isEmpty(struct Stack *st) // 1 = empty_stack = true
{
    if (st->top > 0)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

int isFull(struct Stack *st) // 1 = empty_stack = true
{
    if (st->top >= st->capacity)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    struct Stack *st = createStack(100);

    push(st, 10);
    push(st, 20);
    push(st, 30);

    std::cout << top(st) << " popped from stack\n";
    pop(st);
    std::cout << "Top element is " << top(st) << std::endl;
    std::cout << "Elements present in stack : ";

    // print all elements in stack :
    while (!isEmpty(st))
    {
        // print top element in stack
        std::cout << top(st) << " ";
        // remove top element in stack
        pop(st);
    }

    return 0;
}