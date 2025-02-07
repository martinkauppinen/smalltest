#include "smalltest.hpp"

int fibonacci(int n)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

UNIT_TEST(test_fibonacci)
{
    EXPECT(fibonacci(0) == 0);
    EXPECT(fibonacci(1) == 1);
    EXPECT(fibonacci(2) == 1);
    EXPECT(fibonacci(3) == 2);
    EXPECT(fibonacci(4) == 3);
    EXPECT(fibonacci(5) == 5);
    EXPECT(fibonacci(6) == 8);
    EXPECT(fibonacci(7) == 13);
    EXPECT(fibonacci(8) == 21);
    EXPECT(fibonacci(9) == 34);
    EXPECT(fibonacci(10) == 55);
}