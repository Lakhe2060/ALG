#include <iostream>

class MyClass
{
public:
    MyClass(int value) : value_(value) {}

    bool operator>(const MyClass &other) const
    {
        return value_ > other.value_;
    }

    bool operator<(const MyClass &other) const
    {
        return value_ < other.value_;
    }

    bool operator==(const MyClass &other) const
    {
        return value_ == other.value_;
    }

    bool operator!=(const MyClass &other) const
    {
        return value_ != other.value_;
    }

private:
    int value_;
};

int main()
{
    MyClass a(5);
    MyClass b(10);
    MyClass c(5);

    int choice;
    std::cout << "Enter a number (1-4) to select a comparison operator: ";
    std::cin >> choice;

    switch (choice)
    {
    case 1:
        if (a > b)
        {
            std::cout << "a is greater than b" << std::endl;
        }
        else
        {
            std::cout << "a is not greater than b" << std::endl;
        }
        break;
    case 2:
        if (a < b)
        {
            std::cout << "a is less than b" << std::endl;
        }
        else
        {
            std::cout << "a is not less than b" << std::endl;
        }
        break;
    case 3:
        if (a == c)
        {
            std::cout << "a is equal to c" << std::endl;
        }
        else
        {
            std::cout << "a is not equal to c" << std::endl;
        }
        break;
    case 4:
        if (a != b)
        {
            std::cout << "a is not equal to b" << std::endl;
        }
        else
        {
            std::cout << "a is equal to b" << std::endl;
        }
        break;
    default:
        std::cout << "Invalid choice" << std::endl;
        break;
    }

    return 0;
}
