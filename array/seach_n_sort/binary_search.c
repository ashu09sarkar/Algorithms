#include <stdio.h>

int binarySearch_iterative(int arr[], int l, int r, int key)
{
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (arr[mid] == key)
        {
            return mid;
        }
        else if (arr[mid] > key)
        {
            r = mid - 1;
        }
        else if (arr[mid] < key)
        {
            l = mid + 1;
        }
    }

    return -1;
}

int binarySearch_recursive(int arr[], int l, int r, int key)
{
    if (l <= r)
    {

        int mid = (l + r) / 2;

        if (arr[mid] == key)
        {
            return mid;
        }
        else if (arr[mid] > key)
        {
            return binarySearch_recursive(arr, l, mid - 1, key);
        }
        else if (arr[mid] < key)
        {
            return binarySearch_recursive(arr, mid + 1, r, key);
        }
    }
    return -1;
}

int main()
{
    int arr[] = {9, 4, 5, 6, 2, 0, 1};
    int size = sizeof(arr) / sizeof(arr[0]);

    int key = 5;
    int ret = binarySearch_recursive(arr, 0, size - 1, key);
    printf("Key = %d is found at index = %d \n", key, ret);

    key = 10;
    ret = binarySearch_recursive(arr, 0, size - 1, key);
    printf("Key = %d is found at index = %d \n", key, ret);

    key = 5;
    ret = binarySearch_iterative(arr, 0, size - 1, key);
    printf("Key = %d is found at index = %d \n", key, ret);

    key = 10;
    ret = binarySearch_iterative(arr, 0, size - 1, key);
    printf("Key = %d is found at index = %d \n", key, ret);

    return 0;
}