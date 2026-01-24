//给定一个整数数组 temperatures ，表示每天的温度，返回一个数组 answer ，其中 answer[i] 是指对于第 i 天，下一个更高温度出现
//在几天后。如果气温在这之后都不会升高，请在该位置用 0 来代替。
//
//
//
// 示例 1:
//
//
//输入: temperatures = [73,74,75,71,69,72,76,73]
//输出: [1,1,4,2,1,1,0,0]
//
//
// 示例 2:
//
//
//输入: temperatures = [30,40,50,60]
//输出: [1,1,1,0]
//
//
// 示例 3:
//
//
//输入: temperatures = [30,60,90]
//输出: [1,1,0]
//
//
//
// 提示：
//
//
// 1 <= temperatures.length <= 10⁵
// 30 <= temperatures[i] <= 100
//
//
// Related Topics 栈 数组 单调栈 👍 2096 👎 0


#include "headers.h"


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
  public:

  // 单调栈，从左向右遍历
  vector<int> dailyTemperatures(vector<int> &temperatures) {
    // 栈中存储还没有找到下一个最大的数的下标
    stack<int> s;
    size_t n = temperatures.size();
    vector<int> ans(n, 0);
    for (int i = 0; i < n; ++i) {
      int t = temperatures[i];
      while (!s.empty() && t > temperatures[s.top()]) {
        ans[s.top()] = i - s.top();
        s.pop();
      }
      s.push(i);
    }
    return ans;
  }

  // 单调栈，从右向左遍历
  vector<int> dailyTemperatures2(vector<int> &temperatures) {
    std::stack<int> s;
    size_t n = temperatures.size();
    vector<int> ans(n, 0);
    for (int i = n - 1; i >= 0; i--) {
      int t = temperatures[i];
      while (!s.empty() && t >= temperatures[s.top()]) {
        s.pop();
      }
      if (!s.empty()) {
        ans[i] = s.top() - i;
      }
      s.push(i);
    }
    return ans;
  }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
  Solution s;
  vector<int> arr{73,74,75,71,69,72,76,73};
  auto res = s.dailyTemperatures(arr);
  showVector(res);
}