/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 */

// @lc code=start
class Solution {
 public:
  string longestPalindrome(string s) {
    // 方法1：动态规划
    int n = s.size();
    if (n < 2) {
      return s;
    }

    int begin = 0, maxLen = 1;

    // dp[i][j] 表示 s[i...j]是回文串
    vector<vector<bool>> dp(n, vector<bool>(n));

    // 初始化: 每个字符自身都是回文串
    for (int i = 0; i < n; i++) {
      dp[i][i] = true;
    }
    // 枚举长度
    for (int L = 2; L <= n; L++) {
      // 枚举左边界
      for (int i = 0; i < n; i++) {
        // 根据 L = j - i + 1 计算出右边界
        int j = i + L - 1;
        // 超出边界，即可退出当前循环
        if (j >= n) {
          break;
        }

        // 核心判断逻辑
        if (s[i] != s[j]) {  // 左右边界值不同，说明 i..j 不是回文串
          dp[i][j] = false;
        } else {            // 如果相同
          if (j - i < 3) {  // 判断长度，如果两边界中间只有一个字符
            dp[i][j] = true;  // 说明该串就是回文串，直接返回即可
          } else {            // 否则需要缩小边界，继续判断
            dp[i][j] = dp[i + 1][j - 1];
          }
        }

        // 判断是否要更换最长回文子串的长度
        if (dp[i][j] && j - i + 1 > maxLen) {
          begin = i;
          maxLen = j - i + 1;
        }
      }
    }
    return s.substr(begin, maxLen);
  }
};
// @lc code=end
