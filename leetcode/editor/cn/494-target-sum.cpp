//给你一个整数数组 nums 和一个整数 target 。
//
// 向数组中的每个整数前添加 '+' 或 '-' ，然后串联起所有整数，可以构造一个 表达式 ：
//
//
// 例如，nums = [2, 1] ，可以在 2 之前添加 '+' ，在 1 之前添加 '-' ，然后串联起来得到表达式 "+2-1" 。
//
//
// 返回可以通过上述方法构造的、运算结果等于 target 的不同 表达式 的数目。
//
//
//
// 示例 1：
//
//
//输入：nums = [1,1,1,1,1], target = 3
//输出：5
//解释：一共有 5 种方法让最终目标和为 3 。
//-1 + 1 + 1 + 1 + 1 = 3
//+1 - 1 + 1 + 1 + 1 = 3
//+1 + 1 - 1 + 1 + 1 = 3
//+1 + 1 + 1 - 1 + 1 = 3
//+1 + 1 + 1 + 1 - 1 = 3
//
//
// 示例 2：
//
//
//输入：nums = [1], target = 1
//输出：1
//
//
//
//
// 提示：
//
//
// 1 <= nums.length <= 20
// 0 <= nums[i] <= 1000
// 0 <= sum(nums[i]) <= 1000
// -1000 <= target <= 1000
//
//
// Related Topics 数组 动态规划 回溯 👍 1682 👎 0


#include "headers.h"

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int findTargetSumWays(vector<int> &nums, int target) {
        // positive(正数集合) - negative(负数集合) = target
        // positive + negative = sum
        // -> positive = (target + sum) / 2
        int sum = 0;
        for (auto num: nums) {
            sum += num;
        }
        // 无法整除，说明没有解法
        int positive = (target + sum) / 2;
        if ((target + sum) % 2 == 1 || positive < 0) return 0;
        // 1. dp[i]: 容量为 i 的背包中，选取的重量满足 <= i 的最大方法数
        // 2. dp[i] += dp[i-nums[j]]
        // 3. 初始化
        vector<int> dp(positive + 1, 0);
        dp[0] = 1;
        for (int j = 0; j < nums.size(); ++j) {        // 遍历物品
            for (int i = positive; i >= nums[j]; --i) {// 遍历容量
                dp[i] += dp[i - nums[j]];
            }
        }
        return dp[positive];
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;
    vector<int> arr{7, 1, 5, 3, 6, 4};
    auto res = s.twoSum(arr, 11);
    showVector(res);
}