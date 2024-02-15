#include <iostream>
#include <vector>

// Global variables
int maxVal = 0;
int zeroCount = 0;
std::vector<int> c(1000, 0);
std::vector<int> t = { 3, 4 };

// Function to check if all elements in a list are equal
bool all_equal(const std::vector<int>& lst) {
    for (int i = 1; i < lst.size(); ++i) {
        if (lst[i] != lst[0]) {
            return false;
        }
    }
    return true;
}

// Function to check if a sublist is an arithmetic progression of colour
bool is_arithmetic_progression_of_colour(const std::vector<int>& sublist, int length, int colour) {
    for (int i = 0; i < sublist.size(); ++i) {
        if (sublist[i] != colour) continue;
        for (int j = i + 1; j < sublist.size(); ++j) {
            if (sublist[j] != colour) continue;
            int common_diff = j - i;
            bool valid = true;
            for (int k = 0; k < length; ++k) {
                int index = i + common_diff * k;
                if (index >= sublist.size() || sublist[index] != colour) {
                    valid = false;
                    break;
                }
            }
            if (valid) return true;
        }
    }
    return false;
}

// Main recursive function
void run(int k, int j, int index, int x) {
    auto t_of = [&](int n) -> int {
        return t[n - j];
        };

    std::cout << maxVal << std::endl;

    if (zeroCount > j) return;
    if (index > 0 && x > 0) {
        std::vector<int> current_c(c.begin() + 1, c.begin() + index + 1);
        if (is_arithmetic_progression_of_colour(current_c, t_of(x + j - 1), x)) {
            return;
        }
    }
    if (index > maxVal) {
        maxVal = index;
    }
    for (int i = 0; i <= k - j; ++i) {
        if (i == 0) zeroCount += 1;
        c[index + 1] = i;
        run(k, j, index + 1, i);
        if (i == 0) zeroCount -= 1;
        if (i > 0 && all_equal(t)) {
            if (index <= j + (i - 1) * (t[0] - 1) + 1) {
                bool any_break = false;
                for (int l = 1; l <= index; ++l) {
                    if (c[index + 1] > c[l]) {
                        any_break = true;
                        break;
                    }
                }
                if (any_break) break;
            }
        }
    }
}

int main() {
    run(4, 2, 0, 0);
    std::cout << maxVal + 1 << std::endl;
    return 0;
}
