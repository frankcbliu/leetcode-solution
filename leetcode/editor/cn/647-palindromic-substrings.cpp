//给你一个字符串 s ，请你统计并返回这个字符串中 回文子串 的数目。
//
// 回文字符串 是正着读和倒过来读一样的字符串。
//
// 子字符串 是字符串中的由连续字符组成的一个序列。
//
// 具有不同开始位置或结束位置的子串，即使是由相同的字符组成，也会被视作不同的子串。
//
//
//
// 示例 1：
//
//
//输入：s = "abc"
//输出：3
//解释：三个回文子串: "a", "b", "c"
//
//
// 示例 2：
//
//
//输入：s = "aaa"
//输出：6
//解释：6个回文子串: "a", "a", "a", "aa", "aa", "aaa"
//
//
//
// 提示：
//
//
// 1 <= s.length <= 1000
// s 由小写英文字母组成
//
//
// Related Topics 字符串 动态规划 👍 1210 👎 0


#include "headers.h"

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        // 1. dp[i][j]: s[i:j] 是否为回文子串, 0 <=i,j<= n-1
        // 2. if (s[i] != s[j])
        //       dp[i][j] = false;
        //    else {
        //       i == j // 相同位置, true
        //       i+1 == j // 相邻, 回文子串 true
        //       i+1 < j // 中间还有别的 dp[i+1][j-1]
        //    }
        // 3. 初始化
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        // 4. 遍历顺序
        // (i,j-1)   (i,j)
        // (i+1,j-1) (i+1,j)
        // 从左下到右上
        int cnt = 0;
        for (int i = n - 1; i >= 0; --i) {
            for (int j = i; j < n; ++j) {
                if (s[i] != s[j]) {
                    dp[i][j] = false;
                } else {
                    if ((i == j) || (i + 1 == j)) {
                        dp[i][j] = true;
                    } else if (i + 1 < j) {
                        dp[i][j] = dp[i + 1][j - 1];
                    }
                }
                if (dp[i][j]) cnt++;
            }
        }
        return cnt;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;
    assert(s.countSubstrings("aaa") == 6);
}