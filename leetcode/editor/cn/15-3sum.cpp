//给你一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？请你找出所有和为 0 且不重
//复的三元组。
//
// 注意：答案中不可以包含重复的三元组。
//
//
//
// 示例 1：
//
//
//输入：nums = [-1,0,1,2,-1,-4]
//输出：[[-1,-1,2],[-1,0,1]]
//
//
// 示例 2：
//
//
//输入：nums = []
//输出：[]
//
//
// 示例 3：
//
//
//输入：nums = [0]
//输出：[]
//
//
//
//
// 提示：
//
//
// 0 <= nums.length <= 3000
// -10⁵ <= nums[i] <= 10⁵
//
// Related Topics 数组 双指针 排序 👍 4650 👎 0


#include "headers.h"

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
  public:
  // 在一个函数中完成所有实现
  vector<vector<int>> threeSum(vector<int> &nums) {
    vector<vector<int>> res;
    size_t n = nums.size();
    if (n < 3) return res;
    sort(nums.begin(), nums.end());

    // a:0 ~ n-2, b, c
    for (int i = 0; i < n - 2; ++i) {
      if (i > 0 && nums[i] == nums[i - 1]) continue;

      int a = nums[i];
      int l = i + 1, r = n - 1;
      while (l < r) {
        int b = nums[l], c = nums[r];
        if (a + b + c < 0) {
          while (l < r && nums[l] == b) ++l;
        } else if (a + b + c > 0) {
          while (l < r && nums[r] == c) --r;
        } else {
          res.push_back({a, b, c});
          while (l < r && nums[l] == b) ++l;
          while (l < r && nums[r] == c) --r;
        }
      }
    }
    return res;
  }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
  Solution s;
  vector<int> arr{-100, -70, -60, 110, 120, 130, 160};
  auto res = s.threeSum(arr);
  showVector2(res);
}