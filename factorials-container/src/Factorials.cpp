#include "../include/Factorials.h"
#include <vector>
#include <stdexcept>

std::vector<unsigned long long> Factorials::GenerateFactorials(int n) {
    if (n < 0) {
        throw std::invalid_argument("n must be non-negative");
    }

    std::vector<unsigned long long> result;
    if (n == 0) {
        return result;
    }

    result.push_back(1); // 0! = 1

    for (int i = 1; i < n; ++i) {
        if (result.back() > ULLONG_MAX / i) {
            throw std::overflow_error("Factorial exceeds maximum value");
        }
        result.push_back(result.back() * i);
    }

    return result;
}
