//给你两个字符串 s 和 t ，统计并返回在 s 的 子序列 中 t 出现的个数。
//
// 题目数据保证答案符合 32 位带符号整数范围。
//
//
//
// 示例 1：
//
//
//输入：s = "rabbbit", t = "rabbit"
//输出：3
//解释：
//如下所示, 有 3 种可以从 s 中得到 "rabbit" 的方案。
//[rabb]b[it]
//[rab]b[bit]
//[ra]b[bbit]
// 补充: []中为加粗的部分
//
// 示例 2：
//
//
//输入：s = "babgbag", t = "bag"
//输出：5
//解释：
//如下所示, 有 5 种可以从 s 中得到 "bag" 的方案。
//[ba]b[g]bag
//[ba]bgba[g]
//[b]abgb[ag]
//ba[b]gb[ag]
//babg[bag]
//
//
//
//
// 提示：
//
//
// 1 <= s.length, t.length <= 1000
// s 和 t 由英文字母组成
//
//
// Related Topics 字符串 动态规划 👍 1082 👎 0


#include "headers.h"

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    // 动态规划
    int numDistinct(string s, string t) {
        vector<vector<uint64_t>> dp(s.size() + 1, vector<uint64_t>(t.size() + 1, 0));
        // 1. dp[i][j]: s[0:i-1], t[0:j-1] 中, t是s的子串的数量
        // 2. if(s[i-1] == t[j-1])
        //        dp[i][j] = dp[i-1][j-1] + // 使用 s[i-1]来匹配
        //                   dp[i-1][j] // 不用 s[i-1] 来匹配
        //    else
        //        dp[i][j] = dp[i-1][j] // 没法用s[i-1]来匹配
        // 3. 初始化
        for (int i = 0; i <= s.size(); ++i) {
            dp[i][0] = 1;// t为空串，s 为任意字符串，都有 1 种子串
        }
        // s 为空串，t为任意字符串，则都为 0 种，与 dp 数组的初始化结合在一起
        for (int i = 1; i <= s.size(); ++i) {
            for (int j = 1; j <= t.size(); ++j) {
                if (s[i - 1] == t[j - 1]) {// 这里考虑到是否使用 s[i-1] 来匹配非常关键
                    dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        return dp[s.size()][t.size()];
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;
    vector<int> arr{7, 1, 5, 3, 6, 4};
    auto res = s.twoSum(arr, 11);
    showVector(res);
}