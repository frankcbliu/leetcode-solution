//给你一个整数数组 nums 和一个整数 k ，请你返回子数组内所有元素的乘积严格小于 k 的连续子数组的数目。
//
//
//
// 示例 1：
//
//
//输入：nums = [10,5,2,6], k = 100
//输出：8
//解释：8 个乘积小于 100 的子数组分别为：[10]、[5]、[2]、[6]、[10,5]、[5,2]、[2,6]、[5,2,6]。
//需要注意的是 [10,5,2] 并不是乘积小于 100 的子数组。
//
//
// 示例 2：
//
//
//输入：nums = [1,2,3], k = 0
//输出：0
//
//
//
// 提示:
//
//
// 1 <= nums.length <= 3 * 10⁴
// 1 <= nums[i] <= 1000
// 0 <= k <= 10⁶
//
//
// Related Topics 数组 二分查找 前缀和 滑动窗口 👍 897 👎 0


#include "headers.h"

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
  public:
  int numSubarrayProductLessThanK(vector<int> &nums, int k) {
    // right: 0 -> n-1
    // left: 0 -> right
    // if (left == right), len = 1
    // 子数组个数 = right - left + 1
    if (k <= 1) return 0;
    int prod = 1;
    int left = 0;
    int res = 0;
    for (int i = 0; i < nums.size(); ++i) {
      prod *= nums[i];
      while (prod >= k) {
        prod /= nums[left];
        left++;
      }
      res += i - left + 1;
    }
    return res;
  }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
  Solution s;
  vector<int> arr{1, 2, 3};
  auto res = s.numSubarrayProductLessThanK(arr, 0);
  showVector(res);
}