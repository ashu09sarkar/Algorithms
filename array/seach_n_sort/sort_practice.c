#include <stdio.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
    return;
}

int partition(int arr[], int l, int r)
{
    int i = l - 1;
    int j = l;

    int pivot_index = r;

    for (; j < pivot_index; j++)
    {
        if (arr[j] < arr[pivot_index])
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[++i], &arr[pivot_index]);
    return i;
}

void quickSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int partition_index = partition(arr, l, r);

        quickSort(arr, l, partition_index - 1);
        quickSort(arr, partition_index + 1, r);
    }
}

// arr1[] = {3, 5, 7, 8, 1, 2, 9};
// mid = 3
// l = 0
// r = 6
void merge(int arr[], int l, int mid, int r)
{
    int size_temp = r - l + 1;
    int temp[size_temp];

    int i = l;
    int j = mid + 1;
    int k = 0;
    while (i <= mid && j <= r)
    {
        if (arr[i] <= arr[j])
        {
            temp[k] = arr[i];
            i++;
        }
        else
        {
            temp[k] = arr[j];
            j++;
        }
        k++;
    }

    while (i <= mid)
    {
        temp[k++] = arr[i++];
    }

    while (j <= r)
    {
        temp[k++] = arr[j++];
    }

    for (i = 0; i < size_temp; i++)
    {
        arr[l + i] = temp[i];
    }

    return;
}

int mergeSort(int arr[], int l, int r)
{
    if (r > l)
    {
        int mid = (r + l) / 2;

        mergeSort(arr, l, mid);
        mergeSort(arr, mid + 1, r);
        merge(arr, l, mid, r);
    }
}

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d, ", arr[i]);
    }
    printf("\n");
}

int main()
{
    int arr[] = {5, 7, 3, 8, 2, 9, 1, 4, 6};
    int size = sizeof(arr) / sizeof(arr[0]);
    // mergeSort(arr, 0, size - 1);
    quickSort(arr, 0, size - 1);
    printArray(arr, size);

    return 0;
}