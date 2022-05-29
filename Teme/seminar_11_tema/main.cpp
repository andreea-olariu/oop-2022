#include <stdexcept>
#include <string>
#include <cmath>
#include "catch_amalgamated.hpp"

bool is_even(unsigned x) {
    return x % 2 == 0;
}

bool is_prime(unsigned n) {
    if(n == 0 || n == 1)
        return false;
    for(int d = 2; d <= sqrt(n); d++)
        if(n % d == 0)
            return false;
    return true;
}

TEST_CASE("even") {
    REQUIRE(is_even(2));

    REQUIRE_FALSE(is_even(3));
}

TEST_CASE("prime") {
    REQUIRE(is_prime(7));

    REQUIRE_FALSE(is_prime(15));
}