//Code for linked list implementation using array

// header file to be include.

// avail tells about the index of first empty

//available node.

//List tells about the index of last filled node .

#include <stdio.h>

// to define node.

struct node
{
    int info;

    int next;
};

typedef struct node node1;

//to initiate list.

void initlist(node1 *a, int *list, int *avail)
{
    int i;
    *list = -1;
    avail = 0;

    for (i = 0; i < 4; i++)

        a[i].next = i + 1;

    a[4].next = -1;
}

//to delete any value entered.

void deletell(node1 *a, int *list, int *avail, int x)
{
    int p, back, q;
    p = *list;

    if (a[p].info == x)

    {
        *list = a[p].next;

        a[p].next = *avail;

        *avail = p;
    }

    else

    {
        back = *list;

        q = *list;

        while (q != -1 && a[q].info != x)

        {
            back = q;

            q = a[q].next;
        }

        if (q == -1)

            printf("%d is not in the list", x);

        else

        {
            a[back].next = a[q].next;

            a[q].next = *avail;

            *avail = q;
        }
    }
}

//to check whether list is full.

int FullList(int avail)
{
    if (avail == -1)

        return 1;

    else

        return 0;
}

//to check for empty list

int EmptyList(int list)
{
    if (list == -1)

        return 1;

    else

        return 0;
}

//to search a particular value.

int searchll(node1 *a, int list, int x)
{
    int p;
    p = list;

    while (p != -1 && a[p].info != x)

        p = a[p].next;

    if (p == -1)
        return 0;

    else
        return 1;
}

//to push a value.

void PushList(node1 *a, int *list, int *avail, int x)
{
    int p;

    p = *avail;

    *avail = a[*avail].next;

    a[p].info = x;

    a[p].next = *list;

    *list = p;
}

//to pop a value.

void PopList(node1 *a, int *list, int *avail, int *x)
{
    int p;

    p = *list;

    *list = a[*list].next;

    *x = a[p].info;

    a[p].next = *avail;

    *avail = p;
}

// to print the list.

void printlist(node1 *a, int list)
{
    if (list == -1)

        printf("can't print anything as list is empty.\n");

    else
    {
        while (list != -1)

        {
            printf("%d\t", a[list].info);

            list = a[list].next;
        }
    }
}

// main function.

int main()
{
    node1 a[5];
    int list, avail;
    int i, x;
    int choice;

    initlist(a, &list, &avail);

    do
    {

        printf("select an operation:\n1.push.\n2.pop.\n3.print.\n4.delete.\n5.search.\n6.exit.\n");

        scanf("%d", &choice);

        switch (choice)

        {
        case 1:
            if (FullList(avail) == 1)

                puts("can't push as list is full.'");

            else

            {
                puts("enter the value to be pushed:");
                scanf("%d", &x);

                PushList(a, &list, &avail, x);
            }
            break;

        case 2:
            if (EmptyList(list) == 1)

                puts("can't popped as list is empty.");

            else
            {
                PopList(a, &list, &avail, &x);

                printf("%d is popped out.\n", x);
            }

            break;

        case 3:
            printlist(a, list);
            break;

        case 4:
            puts("enter the value to be deleted:");

            scanf("%d", &x);

            deletell(a, &list, &avail, x);
            break;

        case 5:
            puts("enter the value to be searched:");
            scanf("%d", &x);

            i = searchll(a, list, x);

            if (i == 1)

                puts("value is there.");

            else

                puts("value is not in the list.");

            break;

        case 6:
            puts("program finish run again.");
            break;
        }
    } while (choice != 6);
}