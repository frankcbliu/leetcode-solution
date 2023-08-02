//给定两个单词 word1 和
// word2 ，返回使得
// word1 和
// word2 相同所需的最小步数。
//
// 每步 可以删除任意一个字符串中的一个字符。
//
//
//
// 示例 1：
//
//
//输入: word1 = "sea", word2 = "eat"
//输出: 2
//解释: 第一步将 "sea" 变为 "ea" ，第二步将 "eat "变为 "ea"
//
//
// 示例 2:
//
//
//输入：word1 = "leetcode", word2 = "etco"
//输出：4
//
//
//
//
// 提示：
//
//
//
// 1 <= word1.length, word2.length <= 500
// word1 和 word2 只包含小写英文字母
//
//
// Related Topics 字符串 动态规划 👍 603 👎 0


#include "headers.h"

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.size() + 1, vector<int>(word2.size() + 1, 0));
        // 1. dp[i][j]: word1[0:i-1] 和 word2[0:j-1] 相同所需的最小步数
        // 2.
        //    if (word1[i-1] == word2[j-1])
        //        dp[i][j] = dp[i-1][j-1]; // 不需要删除
        //    else
        //        dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + 1;  // 任意删一边
        // 为什么不考虑两边同时删的情况?
        // dp[i-1][j-1] + 2 >= dp[i-1][j] + 1 &&
        // dp[i-1][j-1] + 2 >= dp[i][j-1] + 1
        // 这两种已经删了一边的情况，最多再删一个，就等同于两边都删的情况的步数了。如果不删也能达到，那么就是更小的情况。
        // 3. 初始化
        //    i: 0->n-1, dp[i][0] = i;
        //    j: 0->m-1, dp[0][j] = j;
        for (int i = 0; i <= word1.size(); ++i) {
            dp[i][0] = i;
        }
        for (int j = 0; j <= word2.size(); ++j) {
            dp[0][j] = j;
        }
        // 4. 遍历顺序
        for (int i = 1; i <= word1.size(); ++i) {
            for (int j = 1; j <= word2.size(); ++j) {
                if (word1[i - 1] == word2[j - 1])
                    dp[i][j] = dp[i - 1][j - 1];// 不需要删除
                else
                    dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + 1;// 任意删一边
            }
        }
        return dp[word1.size()][word2.size()];
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;
    assert(s.minDistance("sea", "eat") == 2);
}