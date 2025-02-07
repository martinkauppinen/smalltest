# Smalltest
This repo is a companion to a [blog post of
mine](https://markau.dev/posts/roll-your-own-gtest/), where I chronicle how a
barebones unit test framework like this one can be created. It contains the
implementation in `src/smalltest.hpp`. Running `make` in the `examples`
directory will build all examples mentioned in the blogpost (plus a couple
extra, except the `examples/multifile` directory, which has its own README and
Makefile).  Some C++17 features, such as structured bindings, are used in the
implementation. These can easily be edited to support older versions.

## Usage
Including `smalltest.hpp` in a test program enables the writing of simple unit tests as follows:

```cpp
#include "smalltest.hpp"

UNIT_TEST(foo)
{
    EXPECT(true);
    ASSERT(true);
}

UNIT_TEST(bar)
{
    // ...
}

// ... and so on

RUN_SMALLTEST();
```

This is not production-ready. It's just a learning project.