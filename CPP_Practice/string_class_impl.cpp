#include <iostream>
#include <cstring>

class String
{
private:
    int size;
    char *str;

public:
    String(const char * = NULL); // Constructor
    String(const String &);      // Copy Constructor

    void change(const char *);  // Function to change
    void print(void);           // Function to print string
    ~String() { delete[] str; } // destructor
};

String::String(const String &s)
{
    size = s.size;
    str = new char[size + 1];

    int i = 0;
    while (s.str[i])
    {
        str[i] = s.str[i];
        i++;
    }
    str[i] = '\0';
}

String::String(const char *s)
{
    size = strlen(s);
    str = new char[size + 1];

    int i = 0;
    while (s[i])
    {
        str[i] = s[i];
        i++;
    }
    str[i] = '\0';
}

void String::change(const char *s)
{
    delete[] str;
    size = strlen(s);
    str = new char[size + 1];

    int i = 0;
    while (s[i])
    {
        str[i] = s[i];
        i++;
    }
    str[i] = '\0';
}

void String::print(void)
{
    std::cout << "String is : " << str << std::endl;
}

int main()
{
    String str1("Ashutosh Sarkar");
    String str2 = str1;

    str1.print(); // what is printed ?
    str2.print();

    str2.change("GeeksforGeeks");

    str1.print(); // what is printed now ?
    str2.print();
    return 0;
}