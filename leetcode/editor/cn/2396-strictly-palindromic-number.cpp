//如果一个整数 n 在 b 进制下（b 为 2 到 n - 2 之间的所有整数）对应的字符串 全部 都是 回文的 ，那么我们称这个数 n 是 严格回文 的。
//
//
// 给你一个整数 n ，如果 n 是 严格回文 的，请返回 true ，否则返回 false 。
//
// 如果一个字符串从前往后读和从后往前读完全相同，那么这个字符串是 回文的 。
//
//
//
// 示例 1：
//
// 输入：n = 9
//输出：false
//解释：在 2 进制下：9 = 1001 ，是回文的。
//在 3 进制下：9 = 100 ，不是回文的。
//所以，9 不是严格回文数字，我们返回 false 。
//注意在 4, 5, 6 和 7 进制下，n = 9 都不是回文的。
//
//
// 示例 2：
//
// 输入：n = 4
//输出：false
//解释：我们只考虑 2 进制：4 = 100 ，不是回文的。
//所以我们返回 false 。
//
//
//
//
// 提示：
//
//
// 4 <= n <= 10⁵
//
//
// Related Topics 脑筋急转弯 数学 双指针 👍 38 👎 0


#include "headers.h"

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
  public:
  bool isHuiWen(string data) {
    int n = data.size();
    for (int i = 0; i < n / 2; ++i) {
      if (data[i] != data[n - 1 - i]) {
        return false;
      }
    }
    return true;
  }

  string change(int n, int b) {
    string res;
    int a = n;
    int c = 0;
    while (a) {
      cout << "a:" << a << " b:" << b << " c:" << c << endl;
      c = a % b;
      res = to_string(c) + res;
      a = a / b;
    }
    return res;
  }

  // 严格回文数
  bool isStrictlyPalindromic(int n) {
    // b: 2~n-2
    for (int i = 2; i <= n - 2; ++i) {
      string data = change(n, i);
      if (!isHuiWen(data)) {
        return false;
      }
    }
    return true;
  }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
  Solution s;
  vector<int> arr{7, 1, 5, 3, 6, 4};
  auto res = s.twoSum(arr, 11);
  showVector(res);
}