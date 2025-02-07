#include "smalltest.hpp"

int lucas(int n)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return 2;
    if (n == 2)
        return 1;
    return lucas(n - 1) + lucas(n - 2);
}

UNIT_TEST(test_lucas)
{
    EXPECT(lucas(0) == 0);
    EXPECT(lucas(1) == 2);
    EXPECT(lucas(2) == 1);
    EXPECT(lucas(3) == 3);
    EXPECT(lucas(4) == 4);
    EXPECT(lucas(5) == 7);
    EXPECT(lucas(6) == 11);
    EXPECT(lucas(7) == 18);
    EXPECT(lucas(8) == 29);
    EXPECT(lucas(9) == 47);
}