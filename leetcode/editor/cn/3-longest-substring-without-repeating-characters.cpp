//给定一个字符串 s ，请你找出其中不含有重复字符的 最长 子串 的长度。
//
//
//
// 示例 1:
//
//
//输入: s = "abcabcbb"
//输出: 3
//解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。注意 "bca" 和 "cab" 也是正确答案。
//
//
// 示例 2:
//
//
//输入: s = "bbbbb"
//输出: 1
//解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。
//
//
// 示例 3:
//
//
//输入: s = "pwwkew"
//输出: 3
//解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
//     请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。
//
//
//
//
// 提示：
//
//
// 0 <= s.length <= 5 * 10⁴
// s 由英文字母、数字、符号和空格组成
//
//
// Related Topics 哈希表 字符串 滑动窗口 👍 11247 👎 0


#include "headers.h"

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
  public:
  // 子串是连续的，子序列才不需要连续
  int lengthOfLongestSubstring(string s) {
    if (s.empty()) return 0;
    int ans = 0;
    // 因为是ASCII码，所以可以用普通数组记录
    int cnt[256] = {0};
    // 使用unordered_map 也是可以的，默认初始化为 0
    // unordered_map<char, int> cnt;
    // right: 0 -> n-1
    // left
    int left = 0;
    for (int right = 0; right < s.size(); right++) {
      cnt[s[right]] += 1;
      while (cnt[s[right]] > 1) {
        cnt[s[left]] -= 1;
        left++;
      }
      ans = max(ans, right - left + 1);
    }
    return ans;
  }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
  Solution s;
  int res = s.lengthOfLongestSubstring("pwwkew");
  cout << res << endl;
}