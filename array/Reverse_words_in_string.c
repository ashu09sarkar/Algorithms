// C++ program to reverse a string

// Example

// Input: s = “geeks quiz practice code”
// Output: s = “code practice quiz geeks”

// Input: s = “getting good at coding needs a lot of practice”
// Output: s = “practice of lot a needs coding at good getting”

#include <stdio.h>
#include <string.h>

void swap(char *s1, char *s2)
{
    char temp = *s1;
    *s1 = *s2;
    *s2 = temp;
}

// Function to reverse words*/
void reverseWords(char *start, char *end)
{
    if (start >= end)
        return;

    swap(start, end);
    reverseWords(++start, --end);
}

// Function to reverse sentence*/
void reverse(char *str)
{
    int len = strlen(str);

    char *start = str;
    char *end = str;

    for (int i = 0; i <= len; i++)
    {
        if ((i > 0) && str[i] != ' ' && str[i - 1] == ' ')
        {
            start = str + i;
        }

        if ((i > 0) && str[i - 1] != ' ' && (str[i] == ' ' || str[i] == '\0'))
        {
            end = str + i - 1;
            reverseWords(start, end);
        }
    }
    // puts(str);
    reverseWords(str, str + len - 1);
}

// Driver Code
int main()
{
    char str[] = "  i like this       program very much";
    reverse(str);
    puts(str);
    return 0;
}
