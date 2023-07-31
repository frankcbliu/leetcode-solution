//给两个整数数组 nums1 和 nums2 ，返回 两个数组中 公共的 、长度最长的子数组的长度 。
//
//
//
// 示例 1：
//
//
//输入：nums1 = [1,2,3,2,1], nums2 = [3,2,1,4,7]
//输出：3
//解释：长度最长的公共子数组是 [3,2,1] 。
//
//
// 示例 2：
//
//
//输入：nums1 = [0,0,0,0,0], nums2 = [0,0,0,0,0]
//输出：5
//
//
//
//
// 提示：
//
//
// 1 <= nums1.length, nums2.length <= 1000
// 0 <= nums1[i], nums2[i] <= 100
//
//
// Related Topics 数组 二分查找 动态规划 滑动窗口 哈希函数 滚动哈希 👍 965 👎 0


#include "headers.h"

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int findLength(vector<int> &nums1, vector<int> &nums2) {
        // 1. dp[i][j]: 数组A以下标 i-1 截止,数组B以 j-1 截止的最长公共子数组长度
        // 2.
        //  if(nums[i-1] == nums[j-1])
        //      dp[i][j] = dp[i-1][j-1] + 1
        // 3. 初始化
        vector<vector<int>> dp(nums1.size() + 1, vector<int>(nums2.size() + 1, 0));
        // dp[1][0] / dp[0][1] 没有意义，但需要初始化为0
        int res = 0;
        for (int i = 1; i <= nums1.size(); ++i) {
            for (int j = 1; j <= nums2.size(); ++j) {
                if (nums1[i - 1] == nums2[j - 1])
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                res = max(res, dp[i][j]);
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