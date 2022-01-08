// 13. Roman to Integer
// https://leetcode.com/problems/roman-to-integer/

#include <gtest/gtest.h>
#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
#include <map>

using namespace std;


class Solution {
public:
    int romanToInt(string s) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        auto symbolToValue = [](char c) -> int {
            switch(c) {
            case 'I': return 1;
            case 'V': return 5;
            case 'X': return 10;
            case 'L': return 50;
            case 'C': return 100;
            case 'D': return 500;
            case 'M': return 1000;
            default: return 0;
            }
            return 0;
        };
        int total = 0;
        for (int i = 0; i < s.size();) {
            if ((i + 1) < s.size()) {
                if ((s[i] == 'I' && (s[i+1] == 'V' || s[i+1] == 'X'))
                        || (s[i] == 'X' && (s[i+1] == 'L' || s[i+1] == 'C'))
                        || (s[i] == 'C' && (s[i+1] == 'D' || s[i+1] == 'M'))) {
                    total += symbolToValue(s[i+1]) - symbolToValue(s[i]);
                    i+=2;
                } else {
                    total += symbolToValue(s[i]);
                    ++i;
                }
            } else {
                total += symbolToValue(s[i]);
                ++i;
            }
        }
        return total;
    }
};

TEST(Solution, romanToInteger1) {
    Solution solution;
    ASSERT_EQ(solution.romanToInt("I"), 1);
    ASSERT_EQ(solution.romanToInt("II"), 2);
    ASSERT_EQ(solution.romanToInt("III"), 3);
}

TEST(Solution, romanToInteger2) {
    Solution solution;
    ASSERT_EQ(solution.romanToInt("LVIII"), 58);
}

TEST(Solution, romanToInteger3) {
    Solution solution;
    ASSERT_EQ(solution.romanToInt("MCMXCIV"), 1994);
}

TEST(Solution, romanToInteger4) {
    Solution solution;
    ASSERT_EQ(solution.romanToInt("CMXCIX"), 999);
}
