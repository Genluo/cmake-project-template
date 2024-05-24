#include "division.h"

auto Division::divide() const -> DivisionResult {
    if (fraction.denominator == 0L) {
        throw DivisionByZero();
    }
    DivisionResult result =
        DivisionResult{fraction.numerator / fraction.denominator,
                       fraction.numerator % fraction.denominator};

    return result;
}
