//给你一个 只包含正整数 的 非空 数组 nums 。请你判断是否可以将这个数组分割成两个子集，使得两个子集的元素和相等。
//
//
//
// 示例 1：
//
//
//输入：nums = [1,5,11,5]
//输出：true
//解释：数组可以分割成 [1, 5, 5] 和 [11] 。
//
// 示例 2：
//
//
//输入：nums = [1,2,3,5]
//输出：false
//解释：数组不能分割成两个元素和相等的子集。
//
//
//
//
// 提示：
//
//
// 1 <= nums.length <= 200
// 1 <= nums[i] <= 100
//
//
// Related Topics 数组 动态规划 👍 1817 👎 0


#include "headers.h"

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool canPartition(vector<int> &nums) {
      // 奇数和不可能分割成两个和相等的子集


    }

    bool canPartition2(vector<int> &nums) {
        int sum = 0;
        for (auto num: nums) {
            sum += num;
        }
        if (sum % 2 == 1) {// 奇数，不可能均分
            return false;
        }
        int target = sum / 2;
        vector<int> dp(target + 1, 0);
        // 1. dp[i]: 从数组中任意取数之和 <= i 的最大值
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = target; j >= nums[i]; --j) {
                dp[j] = max(dp[j], dp[j - nums[i]] + nums[i]);
            }
        }
        return dp[target] == target;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;
    vector<int> arr{1, 5, 11, 5};
    auto res = s.canPartition(arr);
}