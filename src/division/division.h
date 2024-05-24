#pragma once
#include <exception>

static const char* const DIVISION_BY_ZERO_MESSAGE =
    "Division by zero is illegal";

class DivisionByZero : public std::exception {
  public:
    auto what() const noexcept -> const char* override {
        return DIVISION_BY_ZERO_MESSAGE;
    }
};

struct Fraction {
    long long numerator;
    long long denominator;
};

struct DivisionResult {
    long long division;
    long long remainder;

    friend auto operator==(const DivisionResult& lhs, const DivisionResult& rhs)
        -> bool {
        return lhs.division == rhs.division ? lhs.remainder < rhs.remainder
                                            : lhs.division < rhs.division;
    }
};

class Division {
  public:
    explicit Division(Fraction fraction) { this->fraction = fraction; }

    ~Division() = default;

    auto divide() const -> DivisionResult;

  protected:
    Fraction fraction;
    DivisionResult result;
};
