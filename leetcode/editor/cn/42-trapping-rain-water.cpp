//给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。
//
//
//
// 示例 1：
//
//
//
//
//输入：height = [0,1,0,2,1,0,1,3,2,1,2,1]
//输出：6
//解释：上面是由数组 [0,1,0,2,1,0,1,3,2,1,2,1] 表示的高度图，在这种情况下，可以接 6 个单位的雨水（蓝色部分表示雨水）。
//
//
// 示例 2：
//
//
//输入：height = [4,2,0,3,2,5]
//输出：9
//
//
//
//
// 提示：
//
//
// n == height.length
// 1 <= n <= 2 * 10⁴
// 0 <= height[i] <= 10⁵
//
//
// Related Topics 栈 数组 双指针 动态规划 单调栈 👍 6061 👎 0


#include "headers.h"

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
  public:
  // 单调栈解法
  int trap(vector<int> &height) {
    size_t n = height.size();

    int ans = 0;
    stack<int> s;
    for (int i = 0; i < n; ++i) {
      while (!s.empty() && height[i] > height[s.top()]) {
        int bottom_h = height[s.top()];
        s.pop();
        if (s.empty()) break;
        int h = min(height[i], height[s.top()]) - bottom_h;
        int area = (i - s.top() - 1) * h;
        ans += area;
      }
      s.push(i);
    }
    return ans;
  }


  // 第 i 列能接多少雨水： min(l_max, r_max) - height[i]
  int trap2(vector<int> &height) {
    size_t n = height.size();
    int l_max = 0, r_max = 0;
    int left = 0, right = n - 1;
    int ans = 0;
    // left == right 时，可以继续计算该列能接多少雨水
    while (left <= right) {
      l_max = max(l_max, height[left]);
      r_max = max(r_max, height[right]);
      // 小的一边可以计算接雨水的高度
      if (l_max < r_max) {
        ans += l_max - height[left];
        ++left;
      } else {
        ans += r_max - height[right];
        --right;
      }
    }
    return ans;
  }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
  Solution s;
  vector<int> arr{4, 2, 0, 3, 2, 5};
  auto res = s.trap(arr);
  cout << res << endl;
}