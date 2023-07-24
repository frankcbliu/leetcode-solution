//给你一个整数数组 coins 表示不同面额的硬币，另给一个整数 amount 表示总金额。
//
// 请你计算并返回可以凑成总金额的硬币组合数。如果任何硬币组合都无法凑出总金额，返回 0 。
//
// 假设每一种面额的硬币有无限个。
//
// 题目数据保证结果符合 32 位带符号整数。
//
//
//
//
//
//
// 示例 1：
//
//
//输入：amount = 5, coins = [1, 2, 5]
//输出：4
//解释：有四种方式可以凑成总金额：
//5=5
//5=2+2+1
//5=2+1+1+1
//5=1+1+1+1+1
//
//
// 示例 2：
//
//
//输入：amount = 3, coins = [2]
//输出：0
//解释：只用面额 2 的硬币不能凑成总金额 3 。
//
//
// 示例 3：
//
//
//输入：amount = 10, coins = [10]
//输出：1
//
//
//
//
// 提示：
//
//
// 1 <= coins.length <= 300
// 1 <= coins[i] <= 5000
// coins 中的所有值 互不相同
// 0 <= amount <= 5000
//
//
// Related Topics 数组 动态规划 👍 1118 👎 0


#include "headers.h"

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int change(int amount, vector<int> &coins) {
        int n = coins.size();
        // 1. dp[i]: 总金额为 i 的硬币组合数
        // 2. for(i: 0 -> n-1)
        //      for(j: coins[i] -> amount)
        //          dp[j] += dp[j-coin[i]]
        // 3. 初始化
        vector<int> dp(amount + 1, 0);
        dp[0] = 1;
        for (int i = 0; i < n; ++i) {                 // 物品
            for (int j = coins[i]; j <= amount; ++j) {// 容量, 这样求的是组合数
                dp[j] += dp[j - coins[i]];
            }
        }
        return dp[amount];
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;
    int res;
    vector<int> arr;
    {
        arr = {2};
        cout << (res = s.change(3, arr)) << endl;
        assert(res == 0);
    }
    {
        arr = {1, 2, 5};
        cout << (res = s.change(5, arr)) << endl;
        assert(res == 4);
    }
}