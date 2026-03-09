//给你一个整数数组 nums ，你可以对它进行一些操作。
//
// 每次操作中，选择任意一个 nums[i] ，删除它并获得 nums[i] 的点数。之后，你必须删除 所有 等于 nums[i] - 1 和 nums[i]
// + 1 的元素。
//
// 开始你拥有 0 个点数。返回你能通过这些操作获得的最大点数。
//
//
//
// 示例 1：
//
//
//输入：nums = [3,4,2]
//输出：6
//解释：
//你可以执行下列步骤：
//- 删除 4 获得 4 个点数，因此 3 也被删除。nums = [2]。
//- 之后，删除 2 获得 2 个点数。nums = []。
//总共获得 6 个点数。
//
//
// 示例 2：
//
//
//输入：nums = [2,2,3,3,3,4]
//输出：9
//解释：
//你可以执行下列步骤：
//- 删除 3 获得 3 个点数。所有的 2 和 4 也被删除。nums = [3,3]。
//- 之后，再次删除 3 获得 3 个点数。nums = [3]。
//- 再次删除 3 获得 3 个点数。nums = []。
//总共获得 9 个点数。
//
//
//
//
// 提示：
//
//
// 1 <= nums.length <= 2 * 10⁴
// 1 <= nums[i] <= 10⁴
//
//
// Related Topics 数组 哈希表 动态规划 👍 1206 👎 0


#include "headers.h"

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
  public:
  int deleteAndEarn(vector<int> &nums) {
    int max_value = *max_element(nums.begin(), nums.end());
    vector<int> arr(max_value + 1, 0);
    for (int i = 0; i < nums.size(); ++i) {
      arr[nums[i]] += nums[i];
    }
    // 转换数组
    // [3,4,2] -> [0,0,2,3,4]
    // [2,2,3,3,3,4] -> [0,0,4,9,4]
    int p0 = arr[0];
    int p1 = max(arr[0], arr[1]);
    for (int i = 2; i <= max_value; ++i) {
      int p2 = max(p1, p0 + arr[i]);
      p0 = p1;
      p1 = p2;
    }
    return p1;
  }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
  Solution s;
  vector<int> arr{7, 1, 5, 3, 6, 4};
  auto res = s.twoSum(arr, 11);
  showVector(res);
}