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

long long maxArrayValue(vector<int> &nums) {
    int n = nums.size();
    vector<long long> c(n, 0);
    std::copy(nums.begin(), nums.end(), c.begin());
    while (c.size() > 1) {
        n = c.size();
        for (int i = n - 1; i > 0; --i) {
            if (c[i - 1] <= c[i]) {
                c[i] += c[i - 1];
                c.erase(c.begin() + i - 1);
                break;
            }
        }
        if (n == c.size())
            break;
    }
    return *std::max_element(c.begin(), c.end());
}


int maxIncreasingGroups(vector<int> &usageLimits) {
    std::sort(usageLimits.begin(), usageLimits.end());
    // 双指针
    int left = 1, right = usageLimits.size();
    while (left < right) {
        int mid = (left + right + 1) / 2, count = 0;
        for (int i = 0; i < usageLimits.size(); i++) {
            count += max(0, mid - i);
            count -= min(count, usageLimits[usageLimits.size() - i - 1]);
        }
        if (count == 0) {
            left = mid;
        } else {
            right = mid - 1;
        }
    }
    return left;
}

// https://leetcode.cn/problems/number-of-employees-who-met-the-target/
int numberOfEmployeesWhoMetTarget(vector<int>& hours, int target) {
    int cnt = 0;
    for (const auto &item: hours)
        if (item >= target)
            cnt++;
    return cnt;
}

int main() {
    vector<int> arr{8, 50, 65, 85, 8, 73, 55, 50, 29, 95, 5, 68, 52, 79};
    long long res = maxScore(arr, 74);

    arr = {1, 2, 5};
    res = maxIncreasingGroups(arr);
    cout << res << endl;
    assert(res == 3);

    arr = {2, 2, 2};
    res = maxIncreasingGroups(arr);
    cout << res << endl;
    assert(res == 3);

    arr = {1, 1};
    res = maxIncreasingGroups(arr);
    cout << res << endl;
    assert(res == 1);

    arr = {2, 3, 6, 1, 9, 2};
    res = maxScore(arr, 5);
    cout << res << endl;
    assert(res == 13);

    //    cout << res << endl;
    //    assert(res == 470);
    //
    //    arr = {2, 3, 6, 1, 9, 2};
    //    res = maxScore(arr, 5);
    //    cout << res << endl;
    //    assert(res == 13);
    //
    //    res = numberOfWays(10, 2);
    //    cout << res << endl;
    //    assert(res == 1);
    //    res = numberOfWays(4, 1);
    //    cout << res << endl;
    //    assert(res == 2);
    //    res = numberOfWays(2, 2);
    //    cout << res << endl;
    //    assert(res == 0);

    //    arr = {2, 3, 7, 9, 3};
    //    res = maxArrayValue(arr);
    //    cout << res << endl;
    //    assert(res == 21);
    return 0;
}
