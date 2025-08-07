#include <iostream>
#include <cstring>

using namespace std;

class MyString
{
private:
    char *str;
    int length;

public:
    MyString()
    {
        str = NULL;
        length = 0;
    }

    MyString(const char *sources)
    {
        str = NULL;
        length = 0;
        if (sources)
        {
            length = strlen(sources);
            str = new char[length + 1];
            strcpy(str, sources);
        }
    }

    MyString(const MyString &sources)
    {
        str = NULL;
        length = sources.length;

        if (sources.str)
        {
            str = new char[length + 1];
            strcpy(str, sources.str);
        }
    }

    MyString &operator=(const MyString &other);

    int getLength() const
    {
        return length;
    }

    ~MyString()
    {
        delete[] str;
    }

    friend ostream &operator<<(ostream &os, const MyString &myStr)
    {
        os << myStr.str;
        return os;
    }

    friend istream &operator>>(istream &is, MyString &myStr)
    {
        char input_arr[1000];

        is >> input_arr;

        delete[] myStr.str;
        myStr.length = strlen(input_arr);
        myStr.str = new char[myStr.length + 1];
        strcpy(myStr.str, input_arr);

        return is;
    }

    MyString &operator++()
    {
        for (int i = 0; i < length; ++i)
        {
            if (str[i] >= 'a' && str[i] <= 'z')
            {
                str[i] = str[i] - 'a' + 'A';
            }
        }
        return *this;
    }

    char &operator[](int index)
    {
        if (index < 0 || index >= length)
        {
            cout << "Invalid: Index out of bounds." << endl;
            exit(1);
        }
        return str[index];
    }

    bool operator==(const MyString &other) const
    {
        if (length != other.length)
        {
            return false;
        }

        for (int i = 0; i < length; ++i)
        {
            if (str[i] != other.str[i])
            {
                return false;
            }
        }

        return true;
    }
};

MyString &MyString::operator=(const MyString &other)
{
    if (this == &other)
        return *this;

    delete[] str;
    length = other.length;
    if (other.str)
    {
        str = new char[length + 1];
        strcpy(str, other.str);
    }
    else
    {
        str = NULL;
    }

    return *this;
}

int main()
{
    MyString first_str;
    cout << "Enter a string: ";
    cin >> first_str;
    cout << "The original string: " << first_str << endl;

    MyString second_str = first_str;
    cout << "The copied string: " << second_str << endl;

    ++first_str;
    cout << "The string in uppercase is: " << first_str << endl;

    MyString third_str;
    cout << "Enter another string: ";
    cin >> third_str;

    if (second_str == third_str)
    {
        cout << "The strings are equal." << endl;
    }
    else
    {
        cout << "The strings are not equal." << endl;
    }

    cout << "Enter an index to modify character in the copied string: " << endl;
    int num;
    cin >> num;

    if (num < 0)
    {
        cout << "INVALID INPUT OF INDEX" << endl;
        cout << "Please enter the index again:" << endl;
        cin >> num;
    }
    char ch;
    cout << "Enter the character you want to be placed at index: " << endl;
    cin >> ch;
    second_str[num] = ch;
    cout << "The string after modification: " << second_str << endl;

    system("pause");
    return 0;
}

