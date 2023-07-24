//给你一个整数 n ，返回 和为 n 的完全平方数的最少数量 。
//
// 完全平方数 是一个整数，其值等于另一个整数的平方；换句话说，其值等于一个整数自乘的积。例如，1、4、9 和 16 都是完全平方数，而 3 和 11 不是。
//
//
//
//
// 示例 1：
//
//
//输入：n = 12
//输出：3
//解释：12 = 4 + 4 + 4
//
// 示例 2：
//
//
//输入：n = 13
//输出：2
//解释：13 = 4 + 9
//
//
//
// 提示：
//
//
// 1 <= n <= 10⁴
//
//
// Related Topics 广度优先搜索 数学 动态规划 👍 1754 👎 0


#include "headers.h"

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int numSquares(int n) {
        // 1. dp[i]: 和为i的完全平方数的最少数量
        // 2.  for(i: 0 -> coins.size()) //物品
        //       for(j: 0 -> n) // 容量
        //         dp[j] = min(dp[j], dp[j-coins[i]] + 1);
        // 3. 初始化
        vector<unsigned int> dp(n + 1, INT_MAX);
        dp[0] = 0;
        int coin;
        for (int i = 1; (coin = i * i) && (coin <= n); ++i) {
            for (int j = coin; j <= n; ++j) {
                dp[j] = min(dp[j], dp[j - coin] + 1);
            }
        }
        return dp[n];
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;
    vector<int> arr{2, 7, 11, 15};
    auto res = s.twoSum(arr, 9);
    showVector(res);
    arr = {3, 2, 4};
    showVector(s.twoSum(arr, 6));
}