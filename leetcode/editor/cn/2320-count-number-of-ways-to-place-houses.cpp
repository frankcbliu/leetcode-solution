//一条街道上共有 n * 2 个 地块 ，街道的两侧各有 n 个地块。每一边的地块都按从 1 到 n 编号。每个地块上都可以放置一所房子。
//
// 现要求街道同一侧不能存在两所房子相邻的情况，请你计算并返回放置房屋的方式数目。由于答案可能很大，需要对 10⁹ + 7 取余后再返回。
//
// 注意，如果一所房子放置在这条街某一侧上的第 i 个地块，不影响在另一侧的第 i 个地块放置房子。
//
//
//
// 示例 1：
//
// 输入：n = 1
//输出：4
//解释：
//可能的放置方式：
//1. 所有地块都不放置房子。
//2. 一所房子放在街道的某一侧。
//3. 一所房子放在街道的另一侧。
//4. 放置两所房子，街道两侧各放置一所。
//
//
// 示例 2：
// 输入：n = 2
//输出：9
//解释：如上图所示，共有 9 种可能的放置方式。
//
//
//
//
// 提示：
//
//
// 1 <= n <= 10⁴
//
//
// Related Topics 动态规划 👍 30 👎 0


#include "headers.h"

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    // 考虑单侧 + 乘法原理 + 空间优化
    int countHousePlacements5(int n) {
        if (n == 1) return 4;
        int mod = 1e9 + 7;
        auto a = 1ull, b = 2ull, c = 3ull;
        // 1. dp[i]: 单侧i个方块的摆放房子数目
        // 2. 第 i 个方块摆放房子: dp[i] = dp[i-2]
        //    第 i 个方块不摆放房子: dp[i] = dp[i-1]
        // 所以, dp[i] = dp[i-1] + dp[i-2]
        for (int i = 2; i <= n; ++i) {
            c = (b + a) % mod;
            a = b;
            b = c;
        }
        // 乘法原理: 左边独立摆放方式 * 右边独立摆放方式
        return (c * c) % mod;
    }
    // 考虑单侧 + 乘法原理
    int countHousePlacements(int n) {
        if (n == 1) return 4;
        vector<unsigned long long> dp(n + 1, 0);
        int mod = 1e9 + 7;
        dp[0] = 1;
        dp[1] = 2;
        // 1. dp[i]: 单侧i个方块的摆放房子数目
        // 2. 第 i 个方块摆放房子: dp[i] = dp[i-2]
        //    第 i 个方块不摆放房子: dp[i] = dp[i-1]
        // 所以, dp[i] = dp[i-1] + dp[i-2]
        for (int i = 2; i <= n; ++i) {
            dp[i] = (dp[i - 1] + dp[i - 2]) % mod;
        }
        // 乘法原理: 左边独立摆放方式 * 右边独立摆放方式
        return (dp[n] * dp[n]) % mod;
    }
    int countHousePlacements3(int n) {
        if (n == 1) return 4;
        vector<vector<unsigned long long>> dp(n, vector<unsigned long long>(4, 1));
        int mod = 1e9 + 7;
        // 1. dp[i][j]: n=i的时候,三种状态下的放置方式
        //                   j=0, 说明第n行没有房子
        //                   j=1, 说明第n行左边有一个房子
        //                   j=2, 说明第n行右边有一个房子
        //                   j=3, 说明第n行有两个房子
        // 2. 递推公式
        // dp[i][0] = dp[i-1][0] + dp[i-1][1] + dp[i-1][2] + dp[i-1][3]
        // dp[i][1] = dp[i-1][2] + dp[i-1][0]
        // dp[i][2] = dp[i-1][1] + dp[i-1][0]
        // dp[i][3] = dp[i-1][0]
        for (int i = 1; i < n; ++i) {
            dp[i][0] = (dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][2] + dp[i - 1][3]) % mod;
            dp[i][1] = (dp[i - 1][2] + dp[i - 1][0]) % mod;
            dp[i][2] = (dp[i - 1][1] + dp[i - 1][0]) % mod;
            dp[i][3] = dp[i - 1][0];
        }
        return (dp[n - 1][0] + dp[n - 1][1] + dp[n - 1][2] + dp[n - 1][3]) % mod;
    }
    // 优化空间
    int countHousePlacements2(int n) {
        if (n == 1) return 4;
        vector<unsigned long long> dp(4, 1);
        int mod = 1e9 + 7;
        // 1. dp[i][j]: n=i的时候,三种状态下的放置方式
        //                   j=0, 说明第n行没有房子
        //                   j=1, 说明第n行左边有一个房子
        //                   j=2, 说明第n行右边有一个房子
        //                   j=3, 说明第n行有两个房子
        // 2. 递推公式
        // dp[i][0] = dp[i-1][0] + dp[i-1][1] + dp[i-1][2] + dp[i-1][3]
        // dp[i][1] = dp[i-1][2] + dp[i-1][0]
        // dp[i][2] = dp[i-1][1] + dp[i-1][0]
        // dp[i][3] = dp[i-2][0] + dp[i-2][1] + dp[i-2][2] + dp[i-1][3]
        for (int i = 1; i < n; ++i) {
            int a0 = dp[0];
            dp[2] = dp[1] + dp[0];
            dp[0] = (dp[0] + dp[1] * 2 + dp[3]) % mod;
            dp[3] = a0;
            dp[1] = dp[2];
        }
        return (dp[0] + dp[1] + dp[2] + dp[3]) % mod;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;
    int res;
    cout << (res = s.countHousePlacements(1)) << endl;
    assert(4 == res);
    cout << (res = s.countHousePlacements(2)) << endl;
    assert(9 == res);
    cout << (res = s.countHousePlacements(10)) << endl;
    assert(20736 == res);
    cout << (res = s.countHousePlacements(1000)) << endl;
    assert(500478595 == res);
}