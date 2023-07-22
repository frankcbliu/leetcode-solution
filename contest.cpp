//
// Created by frank on 2023/7/23.
//

#include "leetcode/editor/cn/headers.h"
#include <string>

using namespace std;

long long maxScore(vector<int> &nums, int x) {
    int n = nums.size();
    vector<long long> dp(n, -0x3f3f3f);
    dp[0] = nums[0];

    // 初始化，确保从0开始
    long long lmax, rmax;
    if (0 == nums[0] % 2) {
        rmax = dp[0];
        lmax = dp[0] - x;
    } else {
        lmax = dp[0];
        rmax = dp[0] - x;
    }

    for (int j = 1; j < n; ++j) {
        // 本来是再次遍历 0 ~ j-1, 但其实可以优化，只需要考虑前面的最大值所在点是偶数还是奇数
        // 对当前数为偶数、奇数进行分类讨论
        if (nums[j] % 2 == 0) {// 当前点是偶数
            dp[j] = max(rmax + nums[j], lmax + nums[j] - x);
            rmax = max(rmax, dp[j]);
        } else {
            dp[j] = max(lmax + nums[j], rmax + nums[j] - x);
            lmax = max(lmax, dp[j]);
        }
    }
    // 为什么不返回 dp[i]?
    // 因为最大和不一定是停留在 i, 可以停留在 i 之前
    return max(lmax, rmax);
}

int numberOfWays(int n, int x) {
    const int mod = 1e9 + 7;
    // 初始化次幂数组
    vector<long> power;
    for (int i = 1; pow(i, x) <= n; ++i) {
        power.emplace_back(pow(i, x));
    }
    // 1. dp[j]: 容量为 j 的背包，按照条件能存放的集合个数
    // 2. i: 物品(1 -> n开方x)
    //      j: n -> i
    //    dp[j] += dp[j-i]
    vector<int> dp(n + 1, 0);
    dp[0] = 1;
    for (long p: power) {
        for (int j = n; j >= p; --j) {
            dp[j] = (dp[j] + dp[j - p]) % mod;
        }
    }
    return dp[n];
}

int main() {
    vector<int> arr{8, 50, 65, 85, 8, 73, 55, 50, 29, 95, 5, 68, 52, 79};
    long long res = maxScore(arr, 74);
    cout << res << endl;
    assert(res == 470);

    arr = {2, 3, 6, 1, 9, 2};
    res = maxScore(arr, 5);
    cout << res << endl;
    assert(res == 13);

    res = numberOfWays(10, 2);
    cout << res << endl;
    assert(res == 1);
    res = numberOfWays(4, 1);
    cout << res << endl;
    assert(res == 2);
    res = numberOfWays(2, 2);
    cout << res << endl;
    assert(res == 0);
    return 0;
}
