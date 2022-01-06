#include <stdio.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

//   int arr[] = {64, 34, 25, 12, 22, 11, 90};
// Insertion Sort : start with any given i, min should be tracking the minimum element in array,
//                  store that minimum element at i. This way, each pass ensures minimum element at beginning
//              Opposite to BubbleSort
void selectionSort(int arr[], int size)
{
    for (int i = 0; i <= size - 2; i++)
    {
        int min = i;
        for (int j = i + 1; j <= size - 1; j++)
        {
            if (arr[j] < arr[min])
            {
                min = j;
            }
        }
        swap(&arr[i], &arr[min]);
    }
}

//   int arr[] = {64, 34, 25, 12, 22, 11, 90};
// Insertion Sort : Sorting of Cards, at any index i, all previous would be already sorted
void insertionSort(int arr[], int size)
{
    for (int i = 1; i < size; i++)
    {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}

// BubbleSort : Compare and swap adjacent element, place higher to the right, thus each pass places highest at end.
//              Opposite to Selection
void bubbleSort(int arr[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
                swap(&arr[j], &arr[j + 1]);
        }
    }
}

/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main()
{
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int size = sizeof(arr) / sizeof(arr[0]);

    // bubbleSort(arr, size);
    // insertionSort(arr, size);
    selectionSort(arr, size);
    printArray(arr, size);

    return 0;
}