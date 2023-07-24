//给你一个字符串 s 和一个字符串列表 wordDict 作为字典。请你判断是否可以利用字典中出现的单词拼接出 s 。
//
// 注意：不要求字典中出现的单词全部都使用，并且字典中的单词可以重复使用。
//
//
//
// 示例 1：
//
//
//输入: s = "leetcode", wordDict = ["leet", "code"]
//输出: true
//解释: 返回 true 因为 "leetcode" 可以由 "leet" 和 "code" 拼接成。
//
//
// 示例 2：
//
//
//输入: s = "applepenapple", wordDict = ["apple", "pen"]
//输出: true
//解释: 返回 true 因为 "applepenapple" 可以由 "apple" "pen" "apple" 拼接成。
//     注意，你可以重复使用字典中的单词。
//
//
// 示例 3：
//
//
//输入: s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
//输出: false
//
//
//
//
// 提示：
//
//
// 1 <= s.length <= 300
// 1 <= wordDict.length <= 1000
// 1 <= wordDict[i].length <= 20
// s 和 wordDict[i] 仅有小写英文字母组成
// wordDict 中的所有字符串 互不相同
//
//
// Related Topics 字典树 记忆化搜索 数组 哈希表 字符串 动态规划 👍 2203 👎 0


#include "headers.h"

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool wordBreak(string s, vector<string> &wordDict) {
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        int n = s.length();
        vector<bool> dp(n + 1, false);
        dp[0] = true;
        // 1. dp[i]: 0...i长度的背包，能否被字典覆盖
        // 2. for(i: 1 -> n) // 遍历容量
        //      for(j: 0 -> i-1) // 遍历物品
        //          if(j...i-j  in  wordSet)
        //              dp[i] = dp[j]
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j < i; ++j) {// 字符串[j...i-j)
                string word = s.substr(j, i - j);
                if (wordSet.find(word) != wordSet.end() && dp[j]) {
                    dp[i] = true;
                }
            }
        }
        return dp[n];
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;
    vector<string> arr = {"leet", "code"};
    cout << s.wordBreak("leetcode", arr) << endl;
    {
        arr = {"apple", "pen"};
        cout << s.wordBreak("applepenapple", arr) << endl;
    }
    {
        arr = {"aaaa", "aaa"};
        cout << s.wordBreak("aaaaaaa", arr) << endl;
    }
}