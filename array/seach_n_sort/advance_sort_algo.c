#include <stdio.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void merge(int arr[], int low, int mid, int high)
{
    // declare left and right arrays
    int size_l = mid - low + 1;
    int size_r = high - mid;

    int arr_l[size_l], arr_r[size_r];

    // copy to left and right arrays from sorted left-half and right-half of arr[]
    for (int i = 0; i < size_l; i++)
        arr_l[i] = arr[low + i];

    for (int i = 0; i < size_r; i++)
        arr_r[i] = arr[mid + 1 + i];

    int i, j, k;
    i = j = 0;
    k = low;
    // Compare left and right arrays and merge to arr[] in correct order
    while (i < size_l && j < size_r)
    {
        if (arr_l[i] <= arr_r[j])
        {
            arr[k] = arr_l[i];
            i++;
        }
        else
        {
            arr[k] = arr_r[j];
            j++;
        }
        k++;
    }

    while (i < size_l)
    {
        arr[k] = arr_l[i];
        i++;
        k++;
    }

    while (j < size_r)
    {
        arr[k] = arr_r[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int low, int high)
{
    if (high > low)
    {
        int mid = (high + low) / 2;

        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int piIndex = partition(arr, low, high);

        quickSort(arr, low, piIndex - 1);
        quickSort(arr, piIndex + 1, high);
    }
}

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\n");
}

int main()
{
    int arr[] = {10, 7, 8, 9, 1, 5};

    int size = sizeof(arr) / sizeof(arr[0]);
    int low = 0;

    quickSort(arr, 0, size - 1);
    printf("Sorted array: \n");
    printArray(arr, size);

    return 0;
}
