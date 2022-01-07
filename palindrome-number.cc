// 9. Palindrome Number
// https://leetcode.com/problems/palindrome-number/

#include <gtest/gtest.h>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        } else if (x == 0) {
            return true;
        } else if (!(x % 10)) {
            return false;
        }
        string str = to_string(x);
        reverse(str.begin(), str.end());
        int revert_x = atoi(str.c_str());
        return x == revert_x;
    }
};

class Solution2 {
public:
    bool isPalindrome(int x) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        int y = 0;
        while(x > y){
            y = y * 10 + x % 10;
            if (y == 0) {
                return false;
            }
            x /= 10;
        }
        return (x == y || x == y / 10);
    }
};


TEST(Solution, isPalindrome1) {
    Solution solution;
    ASSERT_TRUE(solution.isPalindrome(121));
}

TEST(Solution, isPalindrome2) {
    Solution solution;
    ASSERT_FALSE(solution.isPalindrome(-121));
}

TEST(Solution, isPalindrome3) {
    Solution solution;
    ASSERT_FALSE(solution.isPalindrome(123));
}

TEST(Solution, isPalindrome4) {
    Solution solution;
    ASSERT_FALSE(solution.isPalindrome(10));
}

TEST(Solution2, isPalindrome) {
    Solution2 solution;
    ASSERT_TRUE(solution.isPalindrome(121));
    ASSERT_FALSE(solution.isPalindrome(-121));
    ASSERT_FALSE(solution.isPalindrome(123));
    ASSERT_FALSE(solution.isPalindrome(10));
}
