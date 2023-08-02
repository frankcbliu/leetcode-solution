//给你两个单词 word1 和 word2， 请返回将 word1 转换成 word2 所使用的最少操作数 。
//
// 你可以对一个单词进行如下三种操作：
//
//
// 插入一个字符
// 删除一个字符
// 替换一个字符
//
//
//
//
// 示例 1：
//
//
//输入：word1 = "horse", word2 = "ros"
//输出：3
//解释：
//horse -> rorse (将 'h' 替换为 'r')
//rorse -> rose (删除 'r')
//rose -> ros (删除 'e')
//
//
// 示例 2：
//
//
//输入：word1 = "intention", word2 = "execution"
//输出：5
//解释：
//intention -> inention (删除 't')
//inention -> enention (将 'i' 替换为 'e')
//enention -> exention (将 'n' 替换为 'x')
//exention -> exection (将 'n' 替换为 'c')
//exection -> execution (插入 'u')
//
//
//
//
// 提示：
//
//
// 0 <= word1.length, word2.length <= 500
// word1 和 word2 由小写英文字母组成
//
//
// Related Topics 字符串 动态规划 👍 3055 👎 0


#include "headers.h"

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.size() + 1, vector<int>(word2.size() + 1, 0));
        // 1. dp[i][j]: word1[0:i-1], word2[0:j-1]
        // 2.
        //    if(word1[i-1] == word2[j-1])
        //       dp[i][j] = dp[i-1][j-1];
        //    else
        //       dp[i][j] = min(dp[i-1][j-1],  // 替换操作，相当于两边变成一样的了，但是因为做了操作，所以要 + 1
        //                      min(dp[i-1][j],  // 删除操作, 相当于删除了 word1 的第 i 个字符，word2 不变
        //                          dp[i][j-1])) + 1; // 添加操作, 相当于给 word1 添加了一个字符，所以 word2 要减少一位
        for (int i = 0; i <= word1.size(); ++i) {
            dp[i][0] = i;
        }
        for (int j = 0; j <= word2.size(); ++j) {
            dp[0][j] = j;
        }
        for (int i = 1; i <= word1.size(); ++i) {
            for (int j = 1; j <= word2.size(); ++j) {
                if (word1[i - 1] == word2[j - 1])
                    dp[i][j] = dp[i - 1][j - 1];
                else
                    dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
            }
        }
        return dp[word1.size()][word2.size()];
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;
    vector<int> arr{7, 1, 5, 3, 6, 4};
    auto res = s.twoSum(arr, 11);
    showVector(res);
}