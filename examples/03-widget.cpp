#include <iostream>

class Widget
{
public:
    Widget() { std::cout << "Widget constructor" << std::endl; }
    ~Widget() { std::cout << "Widget destructor" << std::endl; }
} widget;

int main()
{
    std::cout << "Hello, world!" << std::endl;
    return 0;
}