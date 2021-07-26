// 7. Reverse Integer
// https://leetcode.com/problems/reverse-integer/

#include <gtest/gtest.h>

#include <algorithm>
#include <string>

using namespace std;

class Solution {
public:
    int reverse(int x) {
        string str = to_string(x);
        std::reverse(str.begin(), str.end());
        return x < 0 ? stoi(str) * -1 : stoi(str);
    }
};

TEST(Solution, reverse) {
    Solution solution;
    ASSERT_EQ(solution.reverse(123), 321);
    ASSERT_EQ(solution.reverse(-123), -321);
    ASSERT_EQ(solution.reverse(120), 21);
    ASSERT_EQ(solution.reverse(0), 0);
}
