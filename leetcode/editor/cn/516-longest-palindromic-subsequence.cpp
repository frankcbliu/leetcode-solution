//给你一个字符串 s ，找出其中最长的回文子序列，并返回该序列的长度。
//
// 子序列定义为：不改变剩余字符顺序的情况下，删除某些字符或者不删除任何字符形成的一个序列。
//
//
//
// 示例 1：
//
//
//输入：s = "bbbab"
//输出：4
//解释：一个可能的最长回文子序列为 "bbbb" 。
//
//
// 示例 2：
//
//
//输入：s = "cbbd"
//输出：2
//解释：一个可能的最长回文子序列为 "bb" 。
//
//
//
//
// 提示：
//
//
// 1 <= s.length <= 1000
// s 仅由小写英文字母组成
//
//
// Related Topics 字符串 动态规划 👍 1080 👎 0


#include "headers.h"

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        // 1. dp[i][j]: s[i:j] 中最长回文子串长度
        // 2.
        //   if (s[i] == s[j])
        //      dp[i][j] = dp[i+1][j-1] + 1;
        //   else {
        //      dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
        //   }
        // 3. 初始化
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int i = 0; i < n; ++i) {
            dp[i][i] = 1;
        }
        // 4. 遍历顺序
        for (int i = n - 1; i >= 0; --i) {
            for (int j = i + 1; j < n; ++j) { // j=i+1的好处，一个前面 j==i 已经初始化过了，另一个不会导致 j-1 小于0
                if (s[i] == s[j])
                    dp[i][j] = dp[i + 1][j - 1] + 2;
                else {
                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[0][n - 1];
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;
    auto res = s.longestPalindromeSubseq("aabc");
    cout << res << endl;
    assert(res == 4);
    res = s.longestPalindromeSubseq("bbbab");
    cout << res << endl;
    assert(res == 4);
}