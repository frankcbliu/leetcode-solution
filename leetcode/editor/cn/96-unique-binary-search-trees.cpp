//给你一个整数 n ，求恰由 n 个节点组成且节点值从 1 到 n 互不相同的 二叉搜索树 有多少种？
// 返回满足题意的二叉搜索树的种数。
//
//
//
// 示例 1：
//
//
//输入：n = 3
//输出：5
//
//
// 示例 2：
//
//
//输入：n = 1
//输出：1
//
//
//
//
// 提示：
//
//
// 1 <= n <= 19
//
//
// Related Topics 树 二叉搜索树 数学 动态规划 二叉树 👍 2305 👎 0


#include "headers.h"

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int numTrees(int n) {
        // 1.dp[i]: i个节点组成的二叉搜索树的组合个数
        vector<int> dp(n + 1, 0);
        // 2. 递推公式
        // for(j: 1 -> i)
        //  dp[i] += dp[j-1] * dp[i-j]
        // 3. 初始化
        dp[0] = 1; // 根据定义，0 节点也能算一个二叉搜索树(空二叉树)
        dp[1] = 1;
        for (int i = 2; i <= n; ++i) {
            for (int j = 1; j <= i; ++j) {
                dp[i] += dp[j - 1] * dp[i - j];
            }
        }
        return dp[n];
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