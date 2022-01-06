#include <stdio.h>
#include <stdint.h>

// Function to swap even
// and odd bits
uint32_t swapBits(uint32_t x)
{
    uint32_t a = x & 0xAAAAAAAA;
    a = a >> 1;
    uint32_t b = x & 0x55555555;
    b = b << 1;

    return (a | b);
}

int xor_equal_sum(int n)
{
    int count = 0;
    for (int i = 0; i <= n; i++)
    {

        if ((n ^ i) == (n + i))
            count++;
    }
    return count;
}

int bitwise_addition(int a, int b)
{
    return ((a ^ b) + 2 * (a & b));
}

int isPowerof2(int x)
{
    return (x && !(x & x - 1));
}

int lowest_set_bit(int num)
{
    int ret = num & (-num);

    int count = 0;
    while (ret != 1)
    {
        ret = ret >> 1;
        count++;
    }
    return count;
}

void printBinary(int decimal)
{
    int bit = 0;

    for (int i = 31; i >= 0; i--)
    {
        bit = (decimal >> i) & 1;
        printf("%d", bit);
    }

    printf("\n");
}

int findOddElement(int *arr, int size)
{
    int res = 0;

    for (int i = 0; i < size; i++)
    {
        res = res ^ arr[i];
    }

    return res;
}

int main()
{
    int arr[] = {12, 12, 14, 90, 14, 14, 14};
    int x = 19;
    printf("The odd occuring element is : %d\n", findOddElement(arr, sizeof(arr) / sizeof(arr[0])));

    (x & 1) ? printf("The number is odd\n") : printf("The number is even\n");

    printBinary(5);
    printBinary(8);
    printBinary(10);
    printBinary(x);
    printBinary(1);
    printBinary(11);
    printBinary('\0');
    printBinary(0);
    printBinary('0');

    printf("The xor_equal_sum for %d = %d\n", 12, xor_equal_sum(12));
    printf("The bitwise_addition of %d + %d = %d\n", 5, 7, bitwise_addition(5, 7));

    uint32_t c = swapBits(0xAAAAAAAA);
    printBinary(c);

    return 0;
}