
void reverseArray(int arr[], int left, int right)
{
    for(int i = 0, j = right; i < j; i++, j--)
    {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

void leftRotate(int arr[], int d, int size)
{
    if(d == 0)
        return;

    if(d > size)
        d = d % size;
    
    reverseArray(arr, 0, d-1);
    reverseArray(arr, d, size-1);
    reverseArray(arr, 0, size-1);
}

// Function to print an array
void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        printf("%d", arr[i]);
}
  
/* Driver program to test above functions */
int main()
{
    int arr[] = { 1, 2, 3, 4, 5, 6, 7 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int d = 2;
  
    // Function calling
    leftRotate(arr, d, n);
    printArray(arr, n);
  
    return 0;
}