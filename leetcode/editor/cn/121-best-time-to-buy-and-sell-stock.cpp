//给定一个数组 prices ，它的第 i 个元素 prices[i] 表示一支给定股票第 i 天的价格。
//
// 你只能选择 某一天 买入这只股票，并选择在 未来的某一个不同的日子 卖出该股票。设计一个算法来计算你所能获取的最大利润。
//
// 返回你可以从这笔交易中获取的最大利润。如果你不能获取任何利润，返回 0 。
//
//
//
// 示例 1：
//
//
//输入：[7,1,5,3,6,4]
//输出：5
//解释：在第 2 天（股票价格 = 1）的时候买入，在第 5 天（股票价格 = 6）的时候卖出，最大利润 = 6-1 = 5 。
//     注意利润不能是 7-1 = 6, 因为卖出价格需要大于买入价格；同时，你不能在买入前卖出股票。
//
//
// 示例 2：
//
//
//输入：prices = [7,6,4,3,1]
//输出：0
//解释：在这种情况下, 没有交易完成, 所以最大利润为 0。
//
//
//
//
// 提示：
//
//
// 1 <= prices.length <= 10⁵
// 0 <= prices[i] <= 10⁴
//
//
// Related Topics 数组 动态规划 👍 3044 👎 0


#include "headers.h"

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    // 动态规划
    int maxProfit(vector<int> &prices) {
        // 1.定义
        // dp[i][0]: 第 i 天不持有股票的最大现金
        // dp[i][1]: 第 i 天持有股票的最大现金

        // 2. 递推
        // dp[i][0] = max(dp[i-1][0],  // 前一天已经不持有股票
        //                dp[i-1][1] + prices[i]); // 当天卖出
        // dp[i][1] = max(dp[i-1][1],  // 前一天已经持有股票
        //                -prices[i])

        // 3. 初始化
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, 0));
        dp[0][0] = 0;
        dp[0][1] = -prices[0];

        // 4. 遍历顺序
        for (int i = 1; i < n; ++i) {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
            dp[i][1] = max(dp[i - 1][1], -prices[i]);
        }
        return dp[n - 1][0];

        // 空间优化
        // vector<vector<int>> dp(2, vector<int>(2, 0));
        // for (int i = 1; i < n; ++i) {
        //     dp[i % 2][0] = max(dp[(i - 1) % 2][0], dp[(i - 1) % 2][1] + prices[i]);
        //     dp[i % 2][1] = max(dp[(i - 1) % 2][1], -prices[i]);
        // }
        // return dp[(n - 1) % 2][0];
    }

    // 贪心
    int maxProfit2(vector<int> &prices) {
        if (prices.size() < 2)
            return 0;

        int max_profit = 0;
        int min_price = prices[0];
        for (int i = 1; i < prices.size(); ++i) {
            max_profit = max(max_profit, prices[i] - min_price);
            min_price = min(min_price, prices[i]);
        }
        return max_profit;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;
    vector<int> arr{7, 1, 5, 3, 6, 4};
    auto res = s.twoSum(arr, 11);
    showVector(res);
}