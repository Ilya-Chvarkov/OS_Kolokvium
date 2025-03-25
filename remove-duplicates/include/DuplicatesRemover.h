#pragma once
#include <vector>
#include <unordered_set>

class DuplicatesRemover {
public:
    template <typename T>
    static std::vector<T> RemoveDuplicates(const std::vector<T>& input);
};
