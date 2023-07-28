//给定一个整数数组 prices ，它的第 i 个元素 prices[i] 是一支给定的股票在第 i 天的价格，和一个整型 k 。
//
// 设计一个算法来计算你所能获取的最大利润。你最多可以完成 k 笔交易。也就是说，你最多可以买 k 次，卖 k 次。
//
// 注意：你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。
//
//
//
// 示例 1：
//
//
//输入：k = 2, prices = [2,4,1]
//输出：2
//解释：在第 1 天 (股票价格 = 2) 的时候买入，在第 2 天 (股票价格 = 4) 的时候卖出，这笔交易所能获得利润 = 4-2 = 2 。
//
// 示例 2：
//
//
//输入：k = 2, prices = [3,2,6,5,0,3]
//输出：7
//解释：在第 2 天 (股票价格 = 2) 的时候买入，在第 3 天 (股票价格 = 6) 的时候卖出, 这笔交易所能获得利润 = 6-2 = 4 。
//     随后，在第 5 天 (股票价格 = 0) 的时候买入，在第 6 天 (股票价格 = 3) 的时候卖出, 这笔交易所能获得利润 = 3-0 = 3
//。
//
//
//
// 提示：
//
//
// 0 <= k <= 100
// 0 <= prices.length <= 1000
// 0 <= prices[i] <= 1000
//
//
// Related Topics 数组 动态规划 👍 980 👎 0


#include "headers.h"

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    // 空间优化
    int maxProfit(int k, vector<int> &prices) {
        // 1.
        // k=0, dp[2*k+1] = dp[1] // 第(2*k+1)次持有股票
        // k=1, dp[2*k+1] = dp[3]

        int n = prices.size();
        vector<int> dp(2 * k + 1, 0);
        for (int i = 0; i < k; ++i) {
            dp[2 * i + 1] = -prices[0];
        }
        // dp[i][1] = max(dp[i-1][1], dp[i-1][0] - prices[i]);
        // dp[i][2] = max(dp[i-1][2], dp[i-1][1] + prices[i]);
        // dp[i][3] = max(dp[i-1][3], dp[i-1][2] - prices[i]);
        // dp[i][4] = max(dp[i-1][4], dp[i-1][3] + prices[i]);
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < k; ++j) {
                dp[2 * j + 1] = max(dp[2 * j + 1], dp[2 * j] - prices[i]);
                dp[2 * j + 2] = max(dp[2 * j + 2], dp[2 * j + 1] + prices[i]);
            }
        }
        return dp[2 * k];
    }

    int maxProfit2(int k, vector<int> &prices) {
        // 1.
        // k=0, dp[2*k+1] = dp[1] // 第(2*k+1)次持有股票
        // k=1, dp[2*k+1] = dp[3]

        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2 * k + 1, 0));
        for (int i = 0; i < k; ++i) {
            dp[0][2 * i + 1] = -prices[0];
        }
        // dp[i][1] = max(dp[i-1][1], dp[i-1][0] - prices[i]);
        // dp[i][2] = max(dp[i-1][2], dp[i-1][1] + prices[i]);
        // dp[i][3] = max(dp[i-1][3], dp[i-1][2] - prices[i]);
        // dp[i][4] = max(dp[i-1][4], dp[i-1][3] + prices[i]);
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < k; ++j) {
                dp[i][2 * j + 1] = max(dp[i - 1][2 * j + 1], dp[i - 1][2 * j] - prices[i]);
                dp[i][2 * j + 2] = max(dp[i - 1][2 * j + 2], dp[i - 1][2 * j + 1] + prices[i]);
            }
        }
        return dp[n - 1][2 * k];
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;
    vector<int> arr{7, 1, 5, 3, 6, 4};
    auto res = s.twoSum(arr, 11);
    showVector(res);
}