#include "range.h"
#include <cstdlib>

[[nodiscard]] bool Range::isOnePoint() const {
    return left == right;
}
double Range::rand(const Range &d) {
    return (double)std::rand() / RAND_MAX * (d.right - d.left) + d.left;
}