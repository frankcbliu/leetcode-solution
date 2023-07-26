//你是一个专业的小偷，计划偷窃沿街的房屋，每间房内都藏有一定的现金。这个地方所有的房屋都 围成一圈 ，这意味着第一个房屋和最后一个房屋是紧挨着的。同时，相邻的
//房屋装有相互连通的防盗系统，如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警 。
//
// 给定一个代表每个房屋存放金额的非负整数数组，计算你 在不触动警报装置的情况下 ，今晚能够偷窃到的最高金额。
//
//
//
// 示例 1：
//
//
//输入：nums = [2,3,2]
//输出：3
//解释：你不能先偷窃 1 号房屋（金额 = 2），然后偷窃 3 号房屋（金额 = 2）, 因为他们是相邻的。
//
//
// 示例 2：
//
//
//输入：nums = [1,2,3,1]
//输出：4
//解释：你可以先偷窃 1 号房屋（金额 = 1），然后偷窃 3 号房屋（金额 = 3）。
//     偷窃到的最高金额 = 1 + 3 = 4 。
//
// 示例 3：
//
//
//输入：nums = [1,2,3]
//输出：3
//
//
//
//
// 提示：
//
//
// 1 <= nums.length <= 100
// 0 <= nums[i] <= 1000
//
//
// Related Topics 数组 动态规划 👍 1402 👎 0


#include "headers.h"

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int rob(vector<int> &nums) {
        int n = nums.size();
        if (n == 1)
            return nums[0];
        else if (n == 2)
            return max(nums[0], nums[1]);
        // 1. dpc[j]: 0...j 之间的最大金额，左右两端连接
        //    dp[j]: 0...j 之间的最大金额，左右两端不连接
        //    dp1[j]: 1...j 之间的最大金额，左右两端不连接
        // 2. dpc[j] = max(dp[j-1], // 没有j
        //                  dp[1...j-2] + nums[j])
        // 3. 初始化
        vector<int> dp(n, 0), dp1(n, 0);
        dp[0] = nums[0];
        dp1[1] = nums[1];
        dp[1] = max(nums[0], nums[1]);
        dp1[2] = max(nums[1], nums[2]);
        for (int i = 2; i < n; ++i) {
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
            if (i >= 3)
                dp1[i] = max(dp1[i - 1], dp1[i - 2] + nums[i]);
        }
        return max(dp[n - 2], dp1[n - 3] + nums[n - 1]);
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;
    vector<int> arr{1, 1, 3, 6, 7, 10, 7, 1, 8, 5, 9, 1, 4, 4, 3};
    cout << s.rob(arr) << endl; // 预期 41
}