//给你一个整数数组 cost ，其中 cost[i] 是从楼梯第 i 个台阶向上爬需要支付的费用。
// 一旦你支付此费用，即可选择向上爬一个或者两个台阶。
//
// 你可以选择从下标为 0 或下标为 1 的台阶开始爬楼梯。
//
// 请你计算并返回达到楼梯顶部的最低花费。
//
//
//
// 示例 1：
//
//
//输入：cost = [10,15,20]
//输出：15
//解释：你将从下标为 1 的台阶开始。
//- 支付 15 ，向上爬两个台阶，到达楼梯顶部。
//总花费为 15 。
//
//
// 示例 2：
//
//
//输入：cost = [1,100,1,1,1,100,1,1,100,1]
//输出：6
//解释：你将从下标为 0 的台阶开始。
//- 支付 1 ，向上爬两个台阶，到达下标为 2 的台阶。
//- 支付 1 ，向上爬两个台阶，到达下标为 4 的台阶。
//- 支付 1 ，向上爬两个台阶，到达下标为 6 的台阶。
//- 支付 1 ，向上爬一个台阶，到达下标为 7 的台阶。
//- 支付 1 ，向上爬两个台阶，到达下标为 9 的台阶。
//- 支付 1 ，向上爬一个台阶，到达楼梯顶部。
//总花费为 6 。
//
//
//
//
// 提示：
//
//
// 2 <= cost.length <= 1000
// 0 <= cost[i] <= 999
//
//
// Related Topics 数组 动态规划 👍 1270 👎 0


#include "headers.h"

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    // 二刷
    int minCostClimbingStairs(vector<int> &cost) {
        int n = cost.size();
        // 1. dp[i] 到达 第 i 级台阶需要花费的最小金额
        vector<int> dp(n + 1);
        // 2. dp[i] = min(dp[i-1]+cost[i-1], dp[i-2]cost[i-2]);
        for (int i = 2; i <= n; ++i) {
            dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
        }
        return dp[n];
    }

    int minCostClimbingStairs2(vector<int> &cost) {
        size_t n = cost.size();
        if (n <= 1) return 0;
        // 1. dp[n] 到达第 n 级台阶，所花费的最小金额
        // 2. 递推公式: dp[n] = min(dp[n-1]+cost[n-1], dp[n-2]+cost[n-2])
        // 3. 初始化
        //    dp[0] = 0, dp[1] = 0
        int dp[n + 1];
        dp[0] = 0;
        dp[1] = 0;
        // 4. 遍历顺序
        for (int i = 2; i <= n; ++i) {
            dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
        }
        // dp[2] = min(dp[0]+cost[0], dp[1]+cost[1]);
        return dp[n];
    }

    //    优化内存版本
    int minCostClimbingStairs1(vector<int> &cost) {
        size_t n = cost.size();
        if (n <= 1) return 0;
        int dp0, dp1, res;
        dp0 = 0;
        dp1 = 0;
        // 0, 0, cost[0]
        for (int i = 2; i <= n; ++i) {
            res = min(dp0 + cost[i - 2], dp1 + cost[i - 1]);
            dp0 = dp1;
            dp1 = res;
        }
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;
    vector<int> cost{1, 100, 1, 1, 1, 100, 1, 1, 100, 1};
    auto res = s.minCostClimbingStairs(cost);
    cout << res << endl;
}