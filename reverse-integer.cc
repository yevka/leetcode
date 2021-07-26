// 7. Reverse Integer
// https://leetcode.com/problems/reverse-integer/

#include <gtest/gtest.h>

#include <algorithm>
#include <cstdint>
#include <string>
#include <iostream>
#include <climits>

using namespace std;

class Solution {
public:
    int reverse(int x) {
        string str = to_string(abs(x));
        std::reverse(str.begin(), str.end());
        int64_t x64 = stoll(str);
        if (x64 > INT_MAX || x64 < INT_MIN) {
            return 0;
        }
        return x < 0 ? x64 * -1: x64;
    }
};

TEST(Solution, reverse) {
    Solution solution;
    ASSERT_EQ(solution.reverse(123), 321);
    ASSERT_EQ(solution.reverse(-123), -321);
    ASSERT_EQ(solution.reverse(120), 21);
    ASSERT_EQ(solution.reverse(0), 0);
    ASSERT_EQ(solution.reverse(1534236469), 0);
}
