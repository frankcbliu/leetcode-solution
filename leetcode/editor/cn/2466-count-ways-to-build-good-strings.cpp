//给你整数 zero ，one ，low 和 high ，我们从空字符串开始构造一个字符串，每一步执行下面操作中的一种：
//
//
// 将 '0' 在字符串末尾添加 zero 次。
// 将 '1' 在字符串末尾添加 one 次。
//
//
// 以上操作可以执行任意次。
//
// 如果通过以上过程得到一个 长度 在 low 和 high 之间（包含上下边界）的字符串，那么这个字符串我们称为 好 字符串。
//
// 请你返回满足以上要求的 不同 好字符串数目。由于答案可能很大，请将结果对 10⁹ + 7 取余 后返回。
//
//
//
// 示例 1：
//
// 输入：low = 3, high = 3, zero = 1, one = 1
//输出：8
//解释：
//一个可能的好字符串是 "011" 。
//可以这样构造得到："" -> "0" -> "01" -> "011" 。
//从 "000" 到 "111" 之间所有的二进制字符串都是好字符串。
//
//
// 示例 2：
//
// 输入：low = 2, high = 3, zero = 1, one = 2
//输出：5
//解释：好字符串为 "00" ，"11" ，"000" ，"110" 和 "011" 。
//
//
//
//
// 提示：
//
//
// 1 <= low <= high <= 10⁵
// 1 <= zero, one <= low
//
//
// Related Topics 动态规划 👍 156 👎 0


#include "headers.h"

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
  public:
  int countGoodStrings(int low, int high, int zero, int one) {
    const int MOD = 1e9 + 7;
    vector<long long> dp(high + 1, 0);
    dp[zero] += 1;
    dp[one] += 1;
    long long ans = 0;
    for (int i = min(zero, one); i <= high; ++i) {
      if (i >= zero)
        dp[i] = (dp[i] + dp[i - zero]) % MOD;
      if (i >= one)
        dp[i] = (dp[i] + dp[i - one]) % MOD;
      if (i >= low)
        ans += dp[i];
    }
    return ans % MOD;
  }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
  Solution s;
  auto res = s.countGoodStrings(3, 3, 1, 1);
  cout << res << endl;// 期望: 8

  auto res2 = s.countGoodStrings(2, 3, 1, 2);
  cout << res2 << endl;// 期望: 5

  auto res3 = s.countGoodStrings(10, 10, 10, 2);
  cout << res3 << endl;// 期望: 2

  auto res4 = s.countGoodStrings(200, 200, 10, 1);
  cout << res4 << endl;// 期望: 764262396

  auto res5 = s.countGoodStrings(500, 500, 5, 2);
  cout << res5 << endl;// 期望: 873327137
}