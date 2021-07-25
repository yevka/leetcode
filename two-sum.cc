// https://leetcode.com/problems/two-sum/

#include <gtest/gtest.h>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int> &nums, int target) {
        unordered_map<int, int> m;
        m.reserve(nums.size());
        for(int i = 0; i < nums.size(); ++i) {
            int complement = target - nums[i];
            if (m.find(complement) != m.end()) {
                return {i, m[complement]};
            }
            m.emplace(nums[i], i);
        }
        return {};
    }
};

TEST(Solution, twoSum) {
    Solution solution;
    {
        vector<int> nums{2, 7, 11, 15};
        int target = 9;
        const vector<int> sample{0, 1};
        auto ret = solution.twoSum(nums, target);
        for(auto n : sample)
            ASSERT_NE(find(ret.begin(), ret.end(), n), ret.end());
    }
    {
        vector<int> nums{3, 2, 4};
        int target = 6;
        const vector<int> sample{1, 2};
        auto ret = solution.twoSum(nums, target);
        for(auto n : sample)
            ASSERT_NE(find(ret.begin(), ret.end(), n), ret.end());
    }
    {
        vector<int> nums{3, 3};
        int target = 6;
        const vector<int> sample{0, 1};
        auto ret = solution.twoSum(nums, target);
        for(auto n : sample)
            ASSERT_NE(find(ret.begin(), ret.end(), n), ret.end());
    }
    {
        vector<int> nums{3, 2, 3};
        int target = 6;
        const vector<int> sample{0, 2};
        auto ret = solution.twoSum(nums, target);
        for(auto n : sample)
            ASSERT_NE(find(ret.begin(), ret.end(), n), ret.end());
    }
}
