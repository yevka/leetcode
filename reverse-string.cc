// 344. Reverse String
// https://leetcode.com/problems/reverse-string/

#include <gtest/gtest.h>
#include <vector>
#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        for (int i = 0, j = s.size() - 1; i < s.size() / 2 && j >= s.size() / 2; ++i, --j) {
            swap(s[i], s[j]);
        }
    }
};

TEST(Solution, reverseString) {
    Solution solution;
    {
        vector<char> s = {'h', 'e', 'l', 'l', 'o'};
        //                'o', 'l', 'l', 'e', 'h'
        const vector<char> sampleOut = {'o', 'l', 'l', 'e', 'h'};
        solution.reverseString(s);
        ASSERT_EQ(sampleOut, s);
    }
    {
        vector<char> s = {'H', 'a', 'n', 'n', 'a', 'h'};
        const vector<char> sampleOut = {'h', 'a', 'n', 'n', 'a', 'H'};
        solution.reverseString(s);
        ASSERT_EQ(sampleOut, s);
    }
}
