//给定一个正整数 n ，将其拆分为 k 个 正整数 的和（ k >= 2 ），并使这些整数的乘积最大化。
//
// 返回 你可以获得的最大乘积 。
//
//
//
// 示例 1:
//
//
//输入: n = 2
//输出: 1
//解释: 2 = 1 + 1, 1 × 1 = 1。
//
// 示例 2:
//
//
//输入: n = 10
//输出: 36
//解释: 10 = 3 + 3 + 4, 3 × 3 × 4 = 36。
//
//
//
// 提示:
//
//
// 2 <= n <= 58
//
//
// Related Topics 数学 动态规划 👍 1233 👎 0


#include "headers.h"

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n + 1, 0);
        // 1. dp[i]: 拆分正整数i, 能得到的最大乘积
        // 2. dp[i] = max(dp[i], max(j*(i-j), j*dp[i-j]))
        //    单独解释: max(j*(i-j), j*dp[i-j])
        //            - 拆成两个整数: j, i-j
        //            - 拆成多个整数: j, dp[i-j] (即对 i-j 进行拆分), 这里至少 >= 3
        // 3. 初始化
        //    dp[2] = 1
        dp[2] = 1;
        for (int i = 3; i <= n; ++i) {
            for (int j = 1; j < i - 1; ++j) {
                dp[i] = max(dp[i], max(j * (i - j), j * dp[i - j]));
            }
        }
        return dp[n];
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;
    cout << s.integerBreak(12);
}