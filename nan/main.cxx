#include <cmath>
#include <iostream>
#include <limits>
#include "common.h"


int main()
{
    float inf = std::numeric_limits<float>::infinity();
    float nan = std::nan("");
    TEST_VALUE(std::max(inf, nan));
    TEST_VALUE(inf);
    TEST_VALUE(inf == inf);
    TEST_VALUE(nan);
    TEST_VALUE(nan == nan);
    TEST_VALUE(nan > 0);
    TEST_VALUE(nan < 0);
    TEST_VALUE(nan == 0);
    TEST_VALUE(nan < inf);
    TEST_VALUE(inf < nan);
    TEST_VALUE(nan < -inf ? -inf : nan);
    TEST_VALUE(std::max(-3.0f, nan));

    return 0;
}
