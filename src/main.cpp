#include "app.h"
#include <iostream>
#include <thread>
#include <vector>


void foo(std::vector<int> &nums, size_t i) {
    nums[i] += 1;
    std::this_thread::sleep_for(std::chrono::seconds(2));
}

int main() {
    App app;
    app.run();
    return 0;
}








