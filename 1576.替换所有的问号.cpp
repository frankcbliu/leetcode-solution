/*
 * @lc app=leetcode.cn id=1576 lang=cpp
 *
 * [1576] 替换所有的问号
 */

// @lc code=start
class Solution {
 public:
  string modifyString(string s) {
    // 1.暴力法，先遍历?的个数n，然后再遍历n次，每次替换一个?，且与其前后的字母不同
    // 暴力法时间复杂度是 n * 字符串长度s.length, 复杂度太高

    // 2. 简洁一点的版本
    for (int i = 0; i < s.size(); i++) {
      // 当前值是?， 才需要考虑替换
      if (s[i] == '?') {
        // 用空格代替边界情况
        char ahead = (i == 0 ? ' ' : s[i - 1]);
        char behind = (i + 1 == s.size() ? ' ' : s[i + 1]);
        // 从 a 开始遍历
        char temp = 'a';
        // 直到找到和前一个 & 后一个都不一样的字母
        while (temp == ahead || temp == behind) {
          temp++;
        }
        // 替换
        s[i] = temp;
      }
    }
    return s;
  }
};
// @lc code=end
