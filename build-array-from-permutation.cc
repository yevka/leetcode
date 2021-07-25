// 1920. Build Array from Permutation
// https://leetcode.com/problems/build-array-from-permutation/

#include <gtest/gtest.h>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        vector<int> ans(nums.size(), 0);
        for(int i = 0; i < nums.size() ; ++i) {
            ans[i] = nums[nums[i]];
        }
        return ans;
    }
};

TEST(Solution, buildArray) {
    Solution solution;
    {
        vector<int> input {0,2,1,5,3,4};
        const vector<int> sampleOut {0,1,2,4,5,3};
        auto out = solution.buildArray(input);
        ASSERT_EQ(sampleOut, out);
    }
    {
        vector<int> input {5,0,1,2,3,4};
        const vector<int> sampleOut {4,5,0,1,2,3};
        auto out = solution.buildArray(input);
        ASSERT_EQ(sampleOut, out);
    }
}
