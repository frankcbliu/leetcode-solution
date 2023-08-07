//给你一个整数数组 cookies ，其中 cookies[i] 表示在第 i 个零食包中的饼干数量。另给你一个整数 k 表示等待分发零食包的孩子数量，所有
//零食包都需要分发。在同一个零食包中的所有饼干都必须分发给同一个孩子，不能分开。
//
// 分发的 不公平程度 定义为单个孩子在分发过程中能够获得饼干的最大总数。
//
// 返回所有分发的最小不公平程度。
//
//
//
// 示例 1：
//
// 输入：cookies = [8,15,10,20,8], k = 2
//输出：31
//解释：一种最优方案是 [8,15,8] 和 [10,20] 。
//- 第 1 个孩子分到 [8,15,8] ，总计 8 + 15 + 8 = 31 块饼干。
//- 第 2 个孩子分到 [10,20] ，总计 10 + 20 = 30 块饼干。
//分发的不公平程度为 max(31,30) = 31 。
//可以证明不存在不公平程度小于 31 的分发方案。
//
//
// 示例 2：
//
// 输入：cookies = [6,1,3,2,2,4,1,2], k = 3
//输出：7
//解释：一种最优方案是 [6,1]、[3,2,2] 和 [4,1,2] 。
//- 第 1 个孩子分到 [6,1] ，总计 6 + 1 = 7 块饼干。
//- 第 2 个孩子分到 [3,2,2] ，总计 3 + 2 + 2 = 7 块饼干。
//- 第 3 个孩子分到 [4,1,2] ，总计 4 + 1 + 2 = 7 块饼干。
//分发的不公平程度为 max(7,7,7) = 7 。
//可以证明不存在不公平程度小于 7 的分发方案。
//
//
//
//
// 提示：
//
//
// 2 <= cookies.length <= 8
// 1 <= cookies[i] <= 10⁵
// 2 <= k <= cookies.length
//
//
// Related Topics 位运算 数组 动态规划 回溯 状态压缩 👍 75 👎 0


#include "headers.h"

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int distributeCookies(vector<int> &cookies, int k) {
        int n = cookies.size();
        int m = int(pow(2, n + 1)) - 1;
        vector<vector<int>> dp(k + 1, vector<int>(m + 1, 0x7f7f7f));// TODO: 为什么要初始化成最大值?
        // 1. dp[i][j]: i 是第i个人，j 是孩子分配到的饼干的数量和的二进制标识, dp[i][j] 是此时的不公平程度。
        //    假设 8 个小孩: j = 0000 0001 为最后一位小孩分到了饼干
        // 2. 假设第 i 个小朋友分到的饼干是 p, 这 p 个饼干之和是 g[p]。 前 i 个小朋友的饼干之和是 j, 求最小最大值。
        // dp[i][j] = min(dp[i][j],
        //                max(dp[i-1][j-p], // 前 i-1 个小朋友的最小不公平程度
        //                    g[p])); // 第 i 个小朋友的不公平程度
        // 3. 初始化
        vector<int> g(m + 1, 0);// 饼干分配的可能性
        for (int i = 0; i <= m; ++i) {
            int t = i;
            for (int j = 1; j <= n && t > 0; j++) {
                if (t & 1) {
                    g[i] += cookies[n - j];
                }
                t = (t >> 1);
            }
        }
        dp[0][0] = 0;// TODO: 为什么只需要初始化这个?  (0 个人，必然是 0)
        // 4. 遍历顺序
        for (int i = 1; i <= k; ++i) {
            for (int j = 0; j <= m; ++j) {                // 已经分配的饼干
                for (int p = j; p != 0; p = (p - 1) & j) {// TODO: p = (p-1)&j  这是什么遍历顺序?
                    dp[i][j] = min(dp[i][j], max(dp[i - 1][j - p], g[p]));
                }
            }
        }
        return dp[k][m];
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;
    vector<int> arr{8, 15, 10, 20, 8};
    assert(31 == s.distributeCookies(arr, 2));
}