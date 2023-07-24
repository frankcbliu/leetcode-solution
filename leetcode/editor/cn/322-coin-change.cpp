//给你一个整数数组 coins ，表示不同面额的硬币；以及一个整数 amount ，表示总金额。
//
// 计算并返回可以凑成总金额所需的 最少的硬币个数 。如果没有任何一种硬币组合能组成总金额，返回 -1 。
//
// 你可以认为每种硬币的数量是无限的。
//
//
//
// 示例 1：
//
//
//输入：coins = [1, 2, 5], amount = 11
//输出：3
//解释：11 = 5 + 5 + 1
//
// 示例 2：
//
//
//输入：coins = [2], amount = 3
//输出：-1
//
// 示例 3：
//
//
//输入：coins = [1], amount = 0
//输出：0
//
//
//
//
// 提示：
//
//
// 1 <= coins.length <= 12
// 1 <= coins[i] <= 2³¹ - 1
// 0 <= amount <= 10⁴
//
//
// Related Topics 广度优先搜索 数组 动态规划 👍 2486 👎 0


#include "headers.h"

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int coinChange(vector<int> &coins, int amount) {
        int n = coins.size();
        vector<unsigned int> dp(amount + 1, INT_MAX);
        // 1. dp[i]: 总金额为 i 的最少硬币数
        // 2. for(j: 0 -> amount) // 容量
        //      for(i: 0 -> n-1) // 物品重量: coins[i]
        //          dp[j] = min(dp[j], dp[j-coins[i]] + 1);
        // 3. 初始化
        dp[0] = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = coins[i]; j <= amount; ++j) {
                if (dp[j - coins[i]] != INT_MAX)
                    dp[j] = min(dp[j], dp[j - coins[i]] + 1);
            }
        }
        return dp[amount] == INT_MAX ? -1 : dp[amount];
    }
};
//leetcode submit region end(Prohibit modification and deletion)


void check(vector<int> arr, int amount, int res) {
    Solution s;
    int result;
    cout << (result = s.coinChange(arr, amount)) << endl;
    assert(result == res);
}

int main() {
    vector<int> arr;
    check({1, 2, 5}, 11, 3);
    check({2}, 3, -1);
    check({1}, 0, 0);
    check({1}, 1, 1);
    check({1}, 2, 2);
}