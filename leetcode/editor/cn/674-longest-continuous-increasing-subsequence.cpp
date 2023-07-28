//给定一个未经排序的整数数组，找到最长且 连续递增的子序列，并返回该序列的长度。
//
// 连续递增的子序列 可以由两个下标 l 和 r（l < r）确定，如果对于每个 l <= i < r，都有 nums[i] < nums[i + 1] ，那
//么子序列 [nums[l], nums[l + 1], ..., nums[r - 1], nums[r]] 就是连续递增子序列。
//
//
//
// 示例 1：
//
//
//输入：nums = [1,3,5,4,7]
//输出：3
//解释：最长连续递增序列是 [1,3,5], 长度为3。
//尽管 [1,3,5,7] 也是升序的子序列, 但它不是连续的，因为 5 和 7 在原数组里被 4 隔开。
//
//
// 示例 2：
//
//
//输入：nums = [2,2,2,2,2]
//输出：1
//解释：最长连续递增序列是 [2], 长度为1。
//
//
//
//
// 提示：
//
//
// 1 <= nums.length <= 10⁴
// -10⁹ <= nums[i] <= 10⁹
//
//
// Related Topics 数组 👍 402 👎 0


#include "headers.h"

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    // 空间优化
    int findLengthOfLCIS(vector<int> &nums) {
        int n = nums.size();
        int tmp = 1, res = 1;
        for (int i = 1; i < n; ++i) {
            if (nums[i] > nums[i - 1])
                tmp++;
            else
                tmp = 1;
            res = max(res, tmp);
        }
        return res;
    }

    int findLengthOfLCIS2(vector<int> &nums) {
        int n = nums.size();
        // 1. dp[i]: 第i个数为截止的最大连续长度
        vector<int> dp(n, 1);
        int res = 1;
        for (int i = 1; i < n; ++i) {
            if (nums[i] > nums[i - 1])
                dp[i] = dp[i - 1] + 1;
            res = max(res, dp[i]);
        }
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;
    vector<int> arr{2, 7, 11, 15};
    auto res = s.twoSum(arr, 9);
    showVector(res);
    arr = {3, 2, 4};
    showVector(s.twoSum(arr, 6));
}