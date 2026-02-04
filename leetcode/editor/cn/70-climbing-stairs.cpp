//假设你正在爬楼梯。需要 n 阶你才能到达楼顶。
//
// 每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？
//
//
//
// 示例 1：
//
//
//输入：n = 2
//输出：2
//解释：有两种方法可以爬到楼顶。
//1. 1 阶 + 1 阶
//2. 2 阶
//
// 示例 2：
//
//
//输入：n = 3
//输出：3
//解释：有三种方法可以爬到楼顶。
//1. 1 阶 + 1 阶 + 1 阶
//2. 1 阶 + 2 阶
//3. 2 阶 + 1 阶
//
//
//
//
// 提示：
//
//
// 1 <= n <= 45
//
//
// Related Topics 记忆化搜索 数学 动态规划 👍 3124 👎 0


#include "headers.h"

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
  public:
  // 利用完全背包解法
  int climbStairs(int n) {
    int m = 2;
    // 1. dp[i]: 爬到第 i 级楼梯的组合数
    // 2. for(i: 0->n)
    //      for(j: 1->m)
    //          dp[i] += dp[i - j] (i >= j)
    // 3. 初始化
    //    递推式为累加，dp[0] 必须为1, 否则都是 0
    vector<int> dp(n + 1, 0);
    dp[0] = 1;
    for (int i = 0; i <= n; ++i) {  // 容量
      for (int j = 1; j <= m; ++j) {// 物品
        if (i >= j)
          dp[i] += dp[i - j];
      }
    }
    return dp[n];
  }

  int climbStairs2(int n) {
    if (n <= 2) return n;
    int d1, d2, sum;
    d1 = 1;
    d2 = 2;
    for (int i = 3; i <= n; ++i) {
      //        dp[i] = dp[i - 1] + dp[i - 2];
      sum = d1 + d2;
      d1 = d2;
      d2 = sum;
    }
    return sum;
  }

  // 动态规划:递推式
  int climbStairs3(int n) {
    if (n <= 2) return n;
    vector<int> dp(n + 1, 0);
    dp[1] = 1;
    dp[2] = 2;
    for (int i = 3; i <= n; ++i) {
      dp[i] = dp[i - 1] + dp[i - 2];
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