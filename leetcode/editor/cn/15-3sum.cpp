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
      // 0.初始化
      int n = nums.size();
      vector<vector<int>> res;
      if (n < 3) return res;
      res.reserve(64);
      // 1.排序
      sort(nums.begin(), nums.end());
      // 2. 穷举第一个数
      for (int i = 0; i < n - 2; ++i) {
        int a = nums[i];
        // 计算后面的数组中的两数之和
        int l = i + 1, r = n - 1;
        while (l < r) {
          // 三数之和
          int sum = a + nums[l] + nums[r];
          int b = nums[l], c = nums[r];
          if (sum > 0) {
            while (l < r && nums[r] == c) r--;
          } else if (sum < 0) {
            while (l < r && nums[l] == b) l++;
          } else { // sum == 0
            res.push_back({a, b, c});
            while (l < r && nums[l] == b) l++;
            while (l < r && nums[r] == c) r--;
          }
        }
        while (i < n - 1 && nums[i] == nums[i+1]) i++;
      }
      return res;
    }


    vector<vector<int>> threeSum2(vector<int> &nums) {
      // 排序
      sort(nums.begin(), nums.end());
      size_t n = nums.size();
      vector<vector<int>> res;
      // 穷举第一个数
      for (int i = 0; i < n; ++i) {
        int a = nums[i];
        vector<vector<int>> two_res = twoSum(nums, i + 1, 0 - a);
        for (vector<int> &vec: two_res) {
          vec.push_back(a);
          res.push_back(vec);
        }
        while (i < n - 1 && nums[i] == nums[i + 1]) i++;
      }
      return res;
    }

private:
    /**
     * 计算数组所有相加等于 target 的情况
     * @param nums 有序数组
     * @param target 两数之和目标值
     * @return
     */
    vector<vector<int>> twoSum(vector<int> &nums, int start, int target) {
      // 双指针
      int l = start, r = int(nums.size()) - 1;
      vector<vector<int>> res;
      while (l < r) {
        int sum = nums[l] + nums[r];
        int left = nums[l], right = nums[r];
        if (sum < target) {
          while (l < r && nums[l] == left) l++;
        } else if (sum > target) {
          while (l < r && nums[r] == right) r--;
        } else { // 相等的情况
          res.push_back({left, right});
          while (l < r && nums[l] == left) l++;
          while (l < r && nums[r] == right) r--;
        }
      }
      return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
  Solution s;
  vector<int> arr{-1, 0, 1, 2, -1, -4};
  auto res = s.threeSum2(arr);
  showVector2(res);
}