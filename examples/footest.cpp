#include <iostream>
#include "smalltest.hpp"

UNIT_TEST(foo)
{
    EXPECT(true);
    std::cout << "This is fine" << std::endl;
}

UNIT_TEST(bar)
{
    EXPECT(false);
    std::cout << "This is less fine" << std::endl;
}

UNIT_TEST(baz)
{
    ASSERT(false);
    std::cout << "This will never print" << std::endl;
}

RUN_SMALLTEST();