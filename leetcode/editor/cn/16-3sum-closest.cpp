//给你一个长度为 n 的整数数组 nums 和 一个目标值 target。请你从 nums 中选出三个在 不同下标位置 的整数，使它们的和与 target 最
//接近。
//
// 返回这三个数的和。
//
// 假定每组输入只存在恰好一个解。
//
//
//
// 示例 1：
//
//
//输入：nums = [-1,2,1,-4], target = 1
//输出：2
//解释：与 target 最接近的和是 2 (-1 + 2 + 1 = 2)。
//
//
// 示例 2：
//
//
//输入：nums = [0,0,0], target = 1
//输出：0
//解释：与 target 最接近的和是 0（0 + 0 + 0 = 0）。
//
//
//
// 提示：
//
//
// 3 <= nums.length <= 1000
// -1000 <= nums[i] <= 1000
// -10⁴ <= target <= 10⁴
//
//
// Related Topics 数组 双指针 排序 👍 1779 👎 0


#include "headers.h"

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
  public:
  int threeSumClosest(vector<int> &nums, int target) {
    int n = nums.size();
    if (n < 3) return 0;
    int res = nums[0] + nums[1] + nums[2];
    // 先排序
    sort(nums.begin(), nums.end());
    // 双指针
    for (int i = 0; i < n - 2; ++i) {
      if (i > 0 && nums[i] == nums[i - 1]) continue;
      int a = nums[i];
      int l = i + 1, r = n - 1;
      while (l < r) {
        int b = nums[l], c = nums[r];
        int sum = a + b + c;

        if (abs(target - sum) < abs(target - res)) {
          res = sum;
        }

        if (sum < target) {
          ++l;
          while (l < r && nums[l] == b) ++l;
        } else if (sum > target) {
          --r;
          while (l < r && nums[r] == c) --r;
        } else {
          return target;
        }
      }
    }
    return res;
  }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
  Solution s;
  vector<int> arr{7, 1, 5, 3, 6, 4};
  auto res = s.twoSum(arr, 11);
  showVector(res);
}