#include <iostream>
#include <vector>

// Global variables
int maxVal = 0;
int zeroCount = 0;
std::vector<int> c(1000, 0);
std::vector<int> t = { 3, 3 };

// Function to check if all elements in a list are equal
bool all_equal(const std::vector<int>& lst, int j, int k) {
    if(j > lst.size())
        return false;
    for (int i = j; i < lst.size() && i < k; ++i) {
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

    // std::cout << "Curr max: " << maxVal + 1 << std::endl;

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
        if (i > 0 && all_equal(t, j ,k)) {
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

void metaRun(int k, int j, int index, int x) {
    maxVal = 0;
    zeroCount = 0;
    run(k, j, index, x);
    std::cout << "W(" << k << ";";
    for (int i = 0; i < j; i++) {
        std::cout << "2,";
    }
    for (int i=0; i < t.size(); i++) {
        std::cout << t[i];
        if (i < t.size() - 1) {
            std::cout << ",";
        }
    }
    std::cout << ") = " << maxVal + 1 << std::endl;
}

int main() {
    for (int k = 2; k <= 21; k++) {
      int j = k - t.size();
      metaRun(k, j, 0, 0);
    }

    return 0;
}
