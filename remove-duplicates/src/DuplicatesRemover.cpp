#include "DuplicatesRemover.h"
#include <unordered_set>

template <typename T>
std::vector<T> DuplicatesRemover::RemoveDuplicates(const std::vector<T>& input) {
    std::unordered_set<T> seen;
    std::vector<T> result;

    for (const auto& item : input) {
        if (seen.insert(item).second) {
            result.push_back(item);
        }
    }

    return result;
}
