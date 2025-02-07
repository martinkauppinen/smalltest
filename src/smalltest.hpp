#pragma once

#include <cstddef>
#include <cstdlib>
#include <map>
#include <iostream>
#include <string>
#include <vector>

namespace smalltest {
class UnitTest
{
protected:
    virtual void Run() = 0;
    friend class TestRegistry;
};

class TestRegistry
{
public:
    static TestRegistry* GetInstance()
    {
        if (instance_ == nullptr)
        {
            instance_ = new TestRegistry{};
        }
        return instance_;
    }

    void RegisterTest(UnitTest *test, std::string name)
    {
        tests_.insert({test, {name, true}});
    }

    void FailTest(UnitTest *test)
    {
        auto& [name, passed] = tests_[test];
        passed = false;
    }

    int RunTests()
    {
        size_t passed_tests = 0;
        size_t failed_tests = 0;
        std::vector<std::string> fails{};

        for (auto& [test, test_data] : tests_)
        {
            auto& [test_name, passed] = test_data;
            std::cout << "RUN: " << test_name << std::endl;
            test->Run();

            if (passed)
            {
                passed_tests++;
                std::cout << "PASS: " << test_name << std::endl;
            }
            else
            {
                failed_tests++;
                fails.emplace_back(test_name);
                std::cout << "FAIL: " << test_name << std::endl;
            }
        }

        std::cout << "\n";
        std::cout << "Tests run:    " << tests_.size() << "\n";
        std::cout << "Tests passed: " << passed_tests << "\n";
        std::cout << "Tests failed: " << failed_tests << "\n";

        if (failed_tests == 0)
        {
            return EXIT_SUCCESS;
        }

        std::cout << "\nFailed tests:\n";
        for (auto& test : fails)
        {
            std::cout << "\t" << test << "\n";
        }
        return EXIT_FAILURE;
    }

private:
    using TestData = std::tuple<std::string, bool>;
    std::map<UnitTest *, TestData> tests_{};
    static TestRegistry* instance_;
};

} // smalltest

#define RUN_SMALLTEST() smalltest::TestRegistry *smalltest::TestRegistry::instance_ = nullptr;  \
    int main() { return smalltest::TestRegistry::GetInstance()->RunTests(); }

#define UNIT_TEST(test_name)                                                                    \
    class test_name : public ::smalltest::UnitTest {                                            \
    public:                                                                                     \
        test_name()                                                                             \
        {                                                                                       \
            smalltest::TestRegistry::GetInstance()->RegisterTest(this, #test_name);             \
        }                                                                                       \
    protected:                                                                                  \
        void Run() override;                                                                    \
    } test_name;                                                                                \
    void test_name::Run()

#define EXPECT(expr) do                                                                         \
    {                                                                                           \
        if (!(expr))                                                                            \
        {                                                                                       \
            smalltest::TestRegistry::GetInstance()->FailTest(this);                             \
        }                                                                                       \
    } while (false)

#define ASSERT(expr) do                                                                         \
    {                                                                                           \
        if (!(expr))                                                                            \
        {                                                                                       \
            smalltest::TestRegistry::GetInstance()->FailTest(this);                             \
            return;                                                                             \
        }                                                                                       \
    } while (false)
