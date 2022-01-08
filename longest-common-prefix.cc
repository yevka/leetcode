// 14. Longest Common Prefix
// https://leetcode.com/problems/longest-common-prefix/

#include <gtest/gtest.h>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        if(strs.empty()){
            return "";
        }
        size_t minSize = 0;
        for (const auto& str : strs) {
            if (minSize < str.size()) {
                minSize = str.size();
            }
        }
        string prefix = "";
        bool isCommon = true;
        for(size_t i = 0; i < minSize && isCommon; ++i) {
            char curr = strs[0][i];
            char prev;
            for (size_t j = 1; j < strs.size(); ++j) {
                prev = curr;
                curr = strs[j][i];
                if (prev != curr) {
                    isCommon = false;
                    break;
                }
            }
            if (isCommon) {
                prefix += curr;
            }
        }
        return prefix;
    }
};

TEST(Solution, longestCommonPrefix1) {
    Solution solution;
    vector<string> vstr{"flower","flow","flight"};
    ASSERT_EQ(solution.longestCommonPrefix(vstr), string("fl"));
}

TEST(Solution, longestCommonPrefix2) {
    Solution solution;
    vector<string> vstr{"dog","racecar","car"};
    ASSERT_EQ(solution.longestCommonPrefix(vstr), string(""));
}

TEST(Solution, longestCommonPrefix3) {
    Solution solution;
    vector<string> vstr{"cir","car"};
    ASSERT_EQ(solution.longestCommonPrefix(vstr), string("c"));
}
