//给你两个 正 整数 n 和 x 。 
//
// 请你返回将 n 表示成一些 互不相同 正整数的 x 次幂之和的方案数。换句话说，你需要返回互不相同整数 [n1, n2, ..., nk] 的集合数目，满
//足 n = n1ˣ + n2ˣ + ... + nkˣ 。 
//
// 由于答案可能非常大，请你将它对 10⁹ + 7 取余后返回。 
//
// 比方说，n = 160 且 x = 3 ，一个表示 n 的方法是 n = 2³ + 3³ + 5³ 。 
//
// 
//
// 示例 1： 
//
// 输入：n = 10, x = 2
//输出：1
//解释：我们可以将 n 表示为：n = 3² + 1² = 10 。
//这是唯一将 10 表达成不同整数 2 次方之和的方案。
// 
//
// 示例 2： 
//
// 输入：n = 4, x = 1
//输出：2
//解释：我们可以将 n 按以下方案表示：
//- n = 4¹ = 4 。
//- n = 3¹ + 1¹ = 4 。
// 
//
// 
//
// 提示： 
//
// 
// 1 <= n <= 300 
// 1 <= x <= 5 
// 
//
// Related Topics 动态规划 👍 4 👎 0


#include "headers.h"

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int numberOfWays(int n, int x) {
        const int mod = 1e9 + 7;
        // 初始化次幂数组
        vector<long> power;
        for (int i = 1; pow(i, x) <= n; ++i) {
            power.emplace_back(pow(i, x));
        }
        // 1. dp[j]: 容量为 j 的背包，按照条件能存放的集合个数
        // 2. i: 物品(1 -> n开方x)
        //      j: n -> i
        //    dp[j] += dp[j-i]
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        for (long p: power) {
            for (int j = n; j >= p; --j) {
                dp[j] = (dp[j] + dp[j - p]) % mod;
            }
        }
        return dp[n];
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
  Solution s;
  vector<int> arr{7, 1, 5, 3, 6, 4};
  auto res = s.twoSum(arr, 11);
  showVector(res);
}