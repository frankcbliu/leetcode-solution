//给你一个由 不同 整数组成的数组 nums ，和一个目标整数 target 。请你从 nums 中找出并返回总和为 target 的元素组合的个数。
//
// 题目数据保证答案符合 32 位整数范围。
//
//
//
// 示例 1：
//
//
//输入：nums = [1,2,3], target = 4
//输出：7
//解释：
//所有可能的组合为：
//(1, 1, 1, 1)
//(1, 1, 2)
//(1, 2, 1)
//(1, 3)
//(2, 1, 1)
//(2, 2)
//(3, 1)
//请注意，顺序不同的序列被视作不同的组合。
//
//
// 示例 2：
//
//
//输入：nums = [9], target = 3
//输出：0
//
//
//
//
// 提示：
//
//
// 1 <= nums.length <= 200
// 1 <= nums[i] <= 1000
// nums 中的所有元素 互不相同
// 1 <= target <= 1000
//
//
//
//
// 进阶：如果给定的数组中含有负数会发生什么？问题会产生何种变化？如果允许负数出现，需要向题目中添加哪些限制条件？
//
// Related Topics 数组 动态规划 👍 840 👎 0


#include "headers.h"

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int combinationSum4(vector<int> &nums, int target) {
        int n = nums.size();
        // 1. dp[i]: target 为 i 的排列组合数
        // 2. for(i: 0 -> target) // 容量
        //      for(j: 0 -> n-1)  // 物品
        //          dp[i] += dp[i-nums[j]]
        // 3. 初始化
        vector<unsigned long long> dp(target + 1, 0);
        dp[0] = 1;
        for (int i = 0; i <= target; ++i) {// 容量
            for (int j = 0; j < n; ++j) {  // 物品，计算不同的排列数
                if (i >= nums[j]) // 过程卡常: && dp[i] < INT_MAX - dp[i - nums[j]], 更建议用 unsigned ll
                    dp[i] += dp[i - nums[j]];
            }
        }
        return dp[target];
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;
    vector<int> arr{7, 1, 5, 3, 6, 4};
    auto res = s.twoSum(arr, 11);
    showVector(res);
}