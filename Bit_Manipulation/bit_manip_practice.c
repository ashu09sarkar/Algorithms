#include <stdio.h>
#include <math.h>

// Write a modified strcmp function which ignores cases and
// a. returns -1, if s1 < s2,
// b. 0 if s1 = s2,
// c. else returns 1.
// For example, your strcmp should consider “GeeksforGeeks” and
// “geeksforgeeks” as same string.
int strcmp_ignore_case(char *s1, char *s2)
{
    int i = 0;
    for (; s1[i] && s2[i]; i++)
    {
        if ((s1[i] == s2[i]) || ((s1[i] ^ 32) == s2[i]))
            continue;
        else
        {
            break;
        }
    }

    // last character as NULL
    if (s1[i] == s2[i])
        return 0;
    if ((s1[i] | 32) < (s2[i] | 32))
        return -1;
    else
        return 1;
}

void printBinaryPattern(int x)
{
    printf("Bit Pattern for %d : ", x);
    int pos = 31;
    while (pos >= 0)
    {
        int num = (1 << pos) & x;
        printf("%d", ((1 << pos) & x) ? 1 : 0);
        pos--;
    }

    printf("b \n");
}

int isLittleEndian()
{
    int i = 1;
    char *c = (char *)&i;

    printf("Machine is %s \n", (*c == 1) ? "Little Endian" : "Big Endian");
    return *c;
}

void printBinaryPattern_recursive(int x)
{
    if (x == 0)
    {
        printf("\n0b");
        return;
    }

    printBinaryPattern_recursive(x >> 1);
    x = x & 1;
    printf("%d", x);
    return;
}

void find2OddOccuringNum(int arr[], int size)
{
    int xor_of_2_nums = 0;
    for (int i = 0; i < size; i++)
    {
        xor_of_2_nums = xor_of_2_nums ^ arr[i];
    }

    int set_bit = xor_of_2_nums & (-xor_of_2_nums);

    int a = 0;
    int b = 0;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] & set_bit)
            a = a ^ arr[i];
        else
            b = b ^ arr[i];
    }

    printf("\nTwo odd occuring nums are : a = %d and b = %d \n", a, b);
}

int swapBitBlockInNum(unsigned int num, int p1, int p2, int block_size)
{
    unsigned int mask = (1U << block_size) - 1;
    unsigned int block1 = (num >> p1) & mask;
    unsigned int block2 = (num >> p2) & mask;
    unsigned int block = block1 ^ block2;

    num = num ^ (block << p1) ^ (block << p2);
    return num;
}

int addOne_Without_Arithmatic_Ops_1(int x)
{
    int m = 1;

    while (x & m)
    {
        x = x ^ m;
        m = m << 1;
    }

    x = x ^ m;
    return x;
}

int addOne_Without_Arithmatic_Ops_2(int x)
{
    // -X = ~X +1
    // X+1 = -(~X)

    return -(~x);
}

int clearRightMostSetBit_1(int x)
{
    int m = 1;
    while (!(x & m))
    {
        m = m << 1;
    }

    x = x ^ m;
    return x;
}

int clearRightMostSetBit_2(int x)
{
    return x & (x - 1);
}

int isPowerOfTwo(int n)
{
    return (n && !(n & (n - 1)));
}

int isPowerOfFour_bitwise(int n)
{
    // 1. isPowerOfTwo
    // 2. number of zeros are in multiple of two
    // 3. number of zeros are at least 2 i.e. number of zeros at even number always
    if (isPowerOfTwo(n))
    {
        int count = 0;
        int i = 1;

        // printf("Number = %d\n", n);
        while (!(n & 1))
        {
            count++;
            n = n >> 1;
        }
        // printf("count = %d \n", count);

        if (((count % 2) == 0) && isPowerOfTwo(count))
            return 1;
        else
            return 0;
    }

    return 0;
}

int isPowerOfFour_math_log(int n)
{ /*
     // log(x) on base y = m .... means y^m (m is the power) to achieve x
     // so, some number is a power of 4, means log4(num) is always an integer value, not float.
     // so, floor(log4(num)) == ceil(log4(num))

     if (floor(log4(n)) == ceil(log4(n)))
         return 1;
 */
    return 0;
}

void swapNibblesInByte(unsigned char x)
{
    printBinaryPattern(x);
    x = ((x & 0x0F) << 4) | ((x & 0xF0) >> 4);
    printBinaryPattern(x);
}

int main()
{
    int x = 2;
    printf("Adding 1 to %d = %d \n", x, addOne_Without_Arithmatic_Ops_1(x));

    x = 4;
    printf("Adding 1 to %d = %d \n", x, addOne_Without_Arithmatic_Ops_1(x));

    printf("***********  Using Method 2 now ***************** \n");
    x = 2;
    printf("Adding 1 to %d = %d \n", x, addOne_Without_Arithmatic_Ops_2(x));

    x = 4;
    printf("Adding 1 to %d = %d \n", x, addOne_Without_Arithmatic_Ops_2(x));

    printBinaryPattern(2);

    x = 6;
    printBinaryPattern(x);
    printf("Clearing the Right Most Set Bit for : %d :::::::  ", x);
    x = clearRightMostSetBit_2(x);
    printBinaryPattern(x);

    printf("isPowerOfFour(4) = %s \n", isPowerOfFour_bitwise(4) ? "True" : "False");
    printf("isPowerOfFour(3) = %s \n", isPowerOfFour_bitwise(3) ? "True" : "False");
    printf("isPowerOfFour(2) = %s \n", isPowerOfFour_bitwise(2) ? "True" : "False");
    printf("isPowerOfFour(5) = %s \n", isPowerOfFour_bitwise(5) ? "True" : "False");
    printf("isPowerOfFour(8) = %s \n", isPowerOfFour_bitwise(8) ? "True" : "False");
    printf("isPowerOfFour(16) = %s \n", isPowerOfFour_bitwise(16) ? "True" : "False");
    printf("isPowerOfFour(0) = %s \n", isPowerOfFour_bitwise(0) ? "True" : "False");

    int floor_var = floor(3.4);
    int ceil_var = ceil(3.4);

    printf("floor(3.4) = %d \n", floor_var);
    printf("ceil(3.4) = %d \n", ceil_var);

    int arr[] = {4, 2, 4, 5, 2, 3, 3, 1};
    int arr_size = sizeof(arr) / sizeof(arr[0]);
    find2OddOccuringNum(arr, arr_size);

    x = 28;
    printBinaryPattern(x);
    x = swapBitBlockInNum(x, 0, 3, 2);
    printBinaryPattern(x);

    x = 0b00001111;
    x = (5 ^ 6) + 2 * (5 & 6);
    printf("addition is : %d \n", x);

    swapNibblesInByte(100);

    printBinaryPattern_recursive(7);
    printBinaryPattern_recursive(8);

    isLittleEndian();

    printf("ret: %d\n", strcmp_ignore_case("Geeks", "apple"));
    printf("ret: %d\n", strcmp_ignore_case("", "ABCD"));
    printf("ret: %d\n", strcmp_ignore_case("ABCD", "z"));
    printf("ret: %d\n", strcmp_ignore_case("ABCD", "abcdEghe"));
    printf("ret: %d\n", strcmp_ignore_case("GeeksForGeeks", "gEEksFORGeEKs"));
    printf("ret: %d\n", strcmp_ignore_case("GeeksForGeeks", "geeksForGeeks"));
    return 0;
}