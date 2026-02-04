//给你一个整数 n ，求恰由 n 个节点组成且节点值从 1 到 n 互不相同的 二叉搜索树 有多少种？
// 返回满足题意的二叉搜索树的种数。
//
//
//
// 示例 1：
//
//
//输入：n = 3
//输出：5
//
//
// 示例 2：
//
//
//输入：n = 1
//输出：1
//
//
//
//
// 提示：
//
//
// 1 <= n <= 19
//
//
// Related Topics 树 二叉搜索树 数学 动态规划 二叉树 👍 2305 👎 0


#include "headers.h"

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
  public:
  int numTrees(int n) {
    // 根节点从 1 -> n, 左边是 dp[0]=1, 右边是 dp[n-1]
    //                       dp[i] * dp[n-i]
    //                       dp[n-1],      dp[0]
    vector<int> dp(n + 1, 0);
    dp[0] = 1;// 空节点也算一棵树
    dp[1] = 1;
    for (int i = 2; i <= n; ++i) {
      // j: 根节点, 从 1->i
      for (int j = 1; j <= i; ++j) {
        // 核心计算左右子树的节点数，左子树是 j-1 个节点，右子树是 i-j 个节点
        dp[i] += dp[j - 1] * dp[i - j];
      }
    }
    return dp[n];
  }

  int numTrees2(int n) {
    // 1.dp[i]: i个节点组成的二叉搜索树的组合个数
    vector<int> dp(n + 1, 0);
    // 2. 递推公式
    // for(j: 1 -> i)
    //  dp[i] += dp[j-1] * dp[i-j]
    // 3. 初始化
    dp[0] = 1;// 根据定义，0 节点也能算一个二叉搜索树(空二叉树)
    dp[1] = 1;
    for (int i = 2; i <= n; ++i) {
      for (int j = 1; j <= i; ++j) {
        dp[i] += dp[j - 1] * dp[i - j];
      }
    }
    return dp[n];
  }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
  Solution s;
  int res;
  res = s.numTrees(1);
  cout << "n=1, res=" << res << endl;
  res = s.numTrees(2);
  cout << "n=2, res=" << res << endl;
  res = s.numTrees(3);
  cout << "n=3, res=" << res << endl;
}