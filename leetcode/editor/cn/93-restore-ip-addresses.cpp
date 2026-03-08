//有效 IP 地址 正好由四个整数（每个整数位于 0 到 255 之间组成，且不能含有前导 0），整数之间用 '.' 分隔。
//
//
// 例如："0.1.2.201" 和 "192.168.1.1" 是 有效 IP 地址，但是 "0.011.255.245"、"192.168.1.312"
//和 "192.168@1.1" 是 无效 IP 地址。
//
//
// 给定一个只包含数字的字符串 s ，用以表示一个 IP 地址，返回所有可能的有效 IP 地址，这些地址可以通过在 s 中插入 '.' 来形成。你 不能 重新
//排序或删除 s 中的任何数字。你可以按 任何 顺序返回答案。
//
//
//
// 示例 1：
//
//
//输入：s = "25525511135"
//输出：["255.255.11.135","255.255.111.35"]
//
//
// 示例 2：
//
//
//输入：s = "0000"
//输出：["0.0.0.0"]
//
//
// 示例 3：
//
//
//输入：s = "101023"
//输出：["1.0.10.23","1.0.102.3","10.1.0.23","10.10.2.3","101.0.2.3"]
//
//
//
//
// 提示：
//
//
// 1 <= s.length <= 20
// s 仅由数字组成
//
//
// Related Topics 字符串 回溯 👍 1578 👎 0


#include "headers.h"

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
  public:
  vector<string> ans;
  int path[4];// path[i]表示第i段的结束位置+1
  int n;

  void dfs(string &s, int i, int j, int ip_val) {
    if (i == n) {
      if (j == 4) {
        auto [a, b, c, _] = path;
        ans.emplace_back(s.substr(0, a) + "." + s.substr(a, b - a) + "." + s.substr(b, c - b) + "." + s.substr(c));
      }
      return;
    }

    if (j == 4) return;

    ip_val = ip_val * 10 + s[i] - '0';
    if (ip_val > 255) return;

    // 第 i 位后是否加上'.'
    // 不加
    if (ip_val > 0)// 无前导0
      dfs(s, i + 1, j, ip_val);

    // 加上
    path[j] = i + 1;
    dfs(s, i + 1, j + 1, 0);
  }

  vector<string> restoreIpAddresses(string s) {
    n = s.size();
    if (n == 0) return {};
    dfs(s, 0, 0, 0);
    return ans;
  }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
  Solution s;
  auto res = s.restoreIpAddresses("25525511135");
  showVector(res);
}