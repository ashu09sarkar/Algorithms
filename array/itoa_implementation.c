#include <stdio.h>
#include <string.h>

void reverse(char *arr)
{
    int len = strlen(arr);

    for (int i = 0, j = len - 1; i < j; i++, j--)
    {
        char temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

char *itoa(char *arr, int num, int base)
{
    int digit = 0;
    int negative = 0;

    if (num == 0)
    {
        arr[digit++] = '0';
        arr[digit] = '\0';
        return arr;
    }

    // In standard itoa(), negative numbers are handled only with
    // base 10. Otherwise numbers are considered unsigned.
    if (num < 0 && base == 10)
    {
        negative = 1;
        num = -num;
    }

    while (num != 0)
    {
        int remainder = num % base;
        num = num / base;
        arr[digit++] = (remainder <= 9) ? ('0' + remainder) : ('a' + (remainder - 10));
    }

    if (negative)
    {
        arr[digit++] = '-';
    }

    arr[digit] = '\0';

    reverse(arr);
    return arr;
}

int main()
{
    char arr[100] = {0};

    // printf("10 in string format : %s \n", itoa(arr, 10, 10));
    // printf("0 in string format : %s \n", itoa(arr, 0, 10));
    // printf("15 in string format : %s \n", itoa(arr, 15, 10));
    // printf("159 in string format : %s \n", itoa(arr, 159, 10));
    printf("159 in string format : %s \n", itoa(arr, -159, 10));
    printf("1567 base 2 in string format : %s \n", itoa(arr, 1567, 2));
    printf("1567 base 8 in string format : %s \n", itoa(arr, 1567, 8));
    printf("1567 base 16 in string format : %s \n", itoa(arr, 1567, 16));

    return 0;
}