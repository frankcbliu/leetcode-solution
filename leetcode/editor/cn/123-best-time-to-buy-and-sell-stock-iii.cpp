//给定一个数组，它的第 i 个元素是一支给定的股票在第 i 天的价格。
//
// 设计一个算法来计算你所能获取的最大利润。你最多可以完成 两笔 交易。
//
// 注意：你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。
//
//
//
// 示例 1:
//
//
//输入：prices = [3,3,5,0,0,3,1,4]
//输出：6
//解释：在第 4 天（股票价格 = 0）的时候买入，在第 6 天（股票价格 = 3）的时候卖出，这笔交易所能获得利润 = 3-0 = 3 。
//     随后，在第 7 天（股票价格 = 1）的时候买入，在第 8 天 （股票价格 = 4）的时候卖出，这笔交易所能获得利润 = 4-1 = 3 。
//
// 示例 2：
//
//
//输入：prices = [1,2,3,4,5]
//输出：4
//解释：在第 1 天（股票价格 = 1）的时候买入，在第 5 天 （股票价格 = 5）的时候卖出, 这笔交易所能获得利润 = 5-1 = 4 。  
//     注意你不能在第 1 天和第 2 天接连购买股票，之后再将它们卖出。  
//     因为这样属于同时参与了多笔交易，你必须在再次购买前出售掉之前的股票。
//
//
// 示例 3：
//
//
//输入：prices = [7,6,4,3,1]
//输出：0
//解释：在这个情况下, 没有交易完成, 所以最大利润为 0。
//
// 示例 4：
//
//
//输入：prices = [1]
//输出：0
//
//
//
//
// 提示：
//
//
// 1 <= prices.length <= 10⁵
// 0 <= prices[i] <= 10⁵
//
//
// Related Topics 数组 动态规划 👍 1468 👎 0


#include "headers.h"

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    // 空间优化解法
    int maxProfit(vector<int> &prices) {
        int n = prices.size();
        vector<int> dp(5, 0);
        // 1. 状态
        //      dp[i][j]: 第i天, j状态下的最大金额
        // j:
        //    0:无状态
        //    1:第一次持有股票
        //    2:第一次没有股票
        //    3:第二次持有股票
        //    4:第二次没有股票

        // 2. 优化空间算法下，递推公式变成:
        // dp[i][0] = 0;
        // dp[1] = max(dp[1], dp[0] - prices[i]);
        // dp[2] = max(dp[2], dp[1] + prices[i]);
        // dp[3] = max(dp[3], dp[2] - prices[i]);
        // dp[4] = max(dp[4], dp[3] + prices[i]);
        // 第 0 天进行初始化，那么对于第 1 天
        // dp[1] = max(dp[1], // 前一天持有股票的状态
        //             dp[0] - prices[i]); // 当天没有股票的状态 + 当天买入股票
        // dp[2] = max(dp[2], // 前一天没有持有股票的状态
        //             dp[1] + prices[i]); // 当天持有股 + 当天卖出股票
        dp[1] = -prices[0];
        dp[3] = -prices[0];
        // 3. 初始化
        for (int i = 1; i < n; ++i) {
            dp[1] = max(dp[1], dp[0] - prices[i]);
            dp[2] = max(dp[2], dp[1] + prices[i]);
            dp[3] = max(dp[3], dp[2] - prices[i]);
            dp[4] = max(dp[4], dp[3] + prices[i]);
        }
        return dp[4];
    }
    int maxProfit2(vector<int> &prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(5, 0));
        // 1. 状态
        //      dp[i][j]: 第i天, j状态下的最大金额
        // j:
        //    0:无状态
        //    1:第一次持有股票
        //    2:第一次没有股票
        //    3:第二次持有股票
        //    4:第二次没有股票

        // 2. 递推公式
        // dp[i][0] = 0;
        // dp[i][1] = max(dp[i-1][1], dp[i-1][0] - prices[i]);
        // dp[i][2] = max(dp[i-1][2], dp[i-1][1] + prices[i]);
        // dp[i][3] = max(dp[i-1][3], dp[i-1][2] - prices[i]);
        // dp[i][4] = max(dp[i-1][4], dp[i-1][3] + prices[i]);
        dp[0][1] = -prices[0];
        dp[0][3] = -prices[0];
        // 3. 初始化
        for (int i = 1; i < n; ++i) {
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i]);
            dp[i][2] = max(dp[i - 1][2], dp[i - 1][1] + prices[i]);
            dp[i][3] = max(dp[i - 1][3], dp[i - 1][2] - prices[i]);
            dp[i][4] = max(dp[i - 1][4], dp[i - 1][3] + prices[i]);
        }
        return dp[n - 1][4];
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;
    vector<int> arr = {1, 2, 3, 4, 5};
    cout << s.maxProfit(arr) << endl;
}