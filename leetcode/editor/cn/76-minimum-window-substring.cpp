//给定两个字符串 s 和 t，长度分别是 m 和 n，返回 s 中的 最短窗口 子串，使得该子串包含 t 中的每一个字符（包括重复字符）。如果没有这样的子串，
//返回空字符串 ""。
//
// 测试用例保证答案唯一。
//
//
//
// 示例 1：
//
//
//输入：s = "ADOBECODEBANC", t = "ABC"
//输出："BANC"
//解释：最小覆盖子串 "BANC" 包含来自字符串 t 的 'A'、'B' 和 'C'。
//
//
// 示例 2：
//
//
//输入：s = "a", t = "a"
//输出："a"
//解释：整个字符串 s 是最小覆盖子串。
//
//
// 示例 3:
//
//
//输入: s = "a", t = "aa"
//输出: ""
//解释: t 中两个字符 'a' 均应包含在 s 的子串中，
//因此没有符合条件的子字符串，返回空字符串。
//
//
//
// 提示：
//
//
// m == s.length
// n == t.length
// 1 <= m, n <= 10⁵
// s 和 t 由英文字母组成
//
//
//
//进阶：你能设计一个在
//O(m + n) 时间内解决此问题的算法吗？
//
// Related Topics 哈希表 字符串 滑动窗口 👍 3515 👎 0


#include "headers.h"

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
  public:
  unordered_map<char, int> ori, cnt;

  bool check() {
    for (const auto &p: ori) {
      if (cnt[p.first] < p.second) {
        return false;
      }
    }
    return true;
  }

  string minWindow(string s, string t) {
    int m = s.size();
    for (auto c: t)
      ++ori[c];

    int min_val = INT_MAX;// 修复这里
    int l = 0;
    int ansL = -1;
    for (int r = 0; r < m; r++) {// 修复这里，防止越界

      if (ori.count(s[r])) {
        cnt[s[r]]++;
      }

      while (check() && l <= r) {
        int x = r - l + 1;
        if (x < min_val) {
          min_val = x;
          ansL = l;
        }

        if (ori.count(s[l])) {
          cnt[s[l]]--;
        }
        l++;
      }
    }

    return ansL == -1 ? "" : s.substr(ansL, min_val);
  }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
  Solution s;
  vector<int> arr{7, 1, 5, 3, 6, 4};
  auto res = s.twoSum(arr, 11);
  showVector(res);
}