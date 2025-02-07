#include "smalltest.hpp"

#include <chrono>
#include <thread>

UNIT_TEST(test_addition)
{
    auto result = 1 + 1;
    EXPECT(result == 2);
}

UNIT_TEST(test_subtraction)
{
    auto result = 1 - 1;
    EXPECT(result == 0);
}

UNIT_TEST(test_multiplication)
{
    auto result = 2 * 2;
    EXPECT(result == 4);
}

UNIT_TEST(test_division)
{
    auto result = 2 / 2;
    EXPECT(result == 1);
}

UNIT_TEST(failing_addition)
{
    auto result = 2 + 2;
    ASSERT(result == 5);
    std::cout << "This will never print" << std::endl;
}

UNIT_TEST(failing_addition_with_delay)
{
    auto result = 2 + 2;
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    ASSERT(result == 5);
    std::cout << "This will never print" << std::endl;
}

RUN_SMALLTEST();