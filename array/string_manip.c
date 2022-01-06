#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define OFFSETOF(TYPE, ELEMENT) (size_t))&(((TYPE *)0)->ELEMENT)

int my_strstr(const char *main, const char *keyStr)
{
    if (main == NULL || keyStr == NULL)
    {
        puts("\n One of the pointers received is NULL");
        return -1;
    }

    int size_keyStr = strlen(keyStr);
    for (int i = 0; i < strlen(main); i++)
    {
        if (main[i] == keyStr[0])
        {
            for (int j = 0; ((j < size_keyStr) && (main[i + j] != '\0')); j++)
            {
                if (main[i + j] != keyStr[j])
                    break;

                if (main[i + size_keyStr - 1] == keyStr[size_keyStr - 1])
                    return i;
            }
        }
    }

    return -1;
}

void *my_memcpy(void *dest, const void *src, size_t n)
{
    if ((dest == NULL) || (src == NULL))
        return NULL;

    char *d = (char *)dest;
    char *s = (char *)src;

    for (int i = 0; i < n; i++)
        d[i] = s[i];
}

void *my_memmove(void *dest, const void *src, size_t n)
{
    if ((dest == NULL) || (src == NULL))
        return NULL;

    char *d = (char *)dest;
    const char *s = (char *)src;

    char *temp = (char *)malloc(sizeof(char) * n);
    if (!temp)
        return NULL;

    for (int i = 0; i < n; i++)
    {
        temp[i] = s[i];
    }

    for (int i = 0; i < n; i++)
    {
        d[i] = temp[i];
    }

    free(temp);

    return dest;
}

int main()
{
    char str1[] = "Geeks"; // Array of size 100
    char str2[] = "Quiz";  // Array of size 5

    puts("str1 before memmove ");
    puts(str1);

    /* Copies contents of str2 to sr1 */
    my_memmove(str1, str2, sizeof(str2));

    puts("\n str1 after memmove");
    puts(str1);

    int ret = my_strstr("GeeksForGeeks", NULL);

    if (ret != -1)
        printf("String Found at index %d\n", ret);
    else
        printf("String Not Found \n");

    return 0;
}