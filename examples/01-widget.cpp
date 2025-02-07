#include <iostream>

class Widget
{
public:
    Widget() { std::cout << "Widget constructor" << std::endl; }
    ~Widget() { std::cout << "Widget destructor" << std::endl; }
};

int main()
{
    std::cout << "Hello, world!" << std::endl;
    auto widget = Widget{};
    return 0;
}