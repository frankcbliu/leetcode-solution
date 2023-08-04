//Alice 在给 Bob 用手机打字。数字到字母的 对应 如下图所示。
//
//
// 1      2:abc 3:def
// 4:ghi  5:jkl 6:mno
// 7:pqrs 8:tuv 9:wxyz
//
// 为了 打出 一个字母，Alice 需要 按 对应字母 i 次，i 是该字母在这个按键上所处的位置。
//
//
// 比方说，为了按出字母 's' ，Alice 需要按 '7' 四次。类似的， Alice 需要按 '5' 两次得到字母 'k' 。
// 注意，数字 '0' 和 '1' 不映射到任何字母，所以 Alice 不 使用它们。
//
//
// 但是，由于传输的错误，Bob 没有收到 Alice 打字的字母信息，反而收到了 按键的字符串信息 。
//
//
// 比方说，Alice 发出的信息为 "bob" ，Bob 将收到字符串 "2266622" 。
//
//
// 给你一个字符串 pressedKeys ，表示 Bob 收到的字符串，请你返回 Alice 总共可能发出多少种文字信息 。
//
// 由于答案可能很大，将它对 10⁹ + 7 取余 后返回。
//
//
//
// 示例 1：
//
// 输入：pressedKeys = "22233"
//输出：8
//解释：
//Alice 可能发出的文字信息包括：
//"aaadd", "abdd", "badd", "cdd", "aaae", "abe", "bae" 和 "ce" 。
//由于总共有 8 种可能的信息，所以我们返回 8 。
//
//
// 示例 2：
//
// 输入：pressedKeys = "222222222222222222222222222222222222"
//输出：82876089
//解释：
//总共有 2082876103 种 Alice 可能发出的文字信息。
//由于我们需要将答案对 10⁹ + 7 取余，所以我们返回 2082876103 % (10⁹ + 7) = 82876089 。
//
//
//
//
// 提示：
//
//
// 1 <= pressedKeys.length <= 10⁵
// pressedKeys 只包含数字 '2' 到 '9' 。
//
//
// Related Topics 哈希表 数学 字符串 动态规划 👍 40 👎 0


#include "headers.h"

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int countTexts(string pressedKeys) {
        // 映射 2-6,9 -> 3, 7-8 -> 4
        int m[10] = {0, 1, 3, 3, 3, 3, 3, 4, 3, 4};
        vector<pair<int, int>> cnt = {{m[pressedKeys[0] - '0'], 1}};
        int n = 0;
        for (int i = 1; i < pressedKeys.size(); ++i) {
            if (pressedKeys[i] == pressedKeys[i - 1])
                cnt[cnt.size() - 1].second++;
            else
                cnt.push_back({m[pressedKeys[i] - '0'], 1});
            n = max(n, cnt[cnt.size() - 1].second);
        }
        // 1. dp3[i]: 三种字母的情况下,连续按i次的可能种数
        // 2. // 假设末尾分别是三个字母的情况，以 abc 为例子
        //    dp3[i] = dp3[i-1]  // 末尾是 a
        //            +dp3[i-2]  // 末尾是 b
        //            +dp3[i-3]; // 末尾是 c
        // 3. 初始化
        // 空串也是一种可能，考虑递推公式是从前递增的，所以 dp3[0] 也只能为 1
        vector<uint64_t> dp3 = {1, 1, 2, 4};
        vector<uint64_t> dp4 = {1, 1, 2, 4};
        const int mod = 1e9 + 7;
        // 4. 遍历
        for (int i = 4; i <= n; ++i) {
            dp3.push_back((dp3[i - 1] + dp3[i - 2] + dp3[i - 3]) % mod);
            dp4.push_back((dp4[i - 1] + dp4[i - 2] + dp4[i - 3] + dp4[i - 4]) % mod);
        }
        int res = 1;
        for (auto item: cnt) {
            if (item.first == 3) {
                res = res * dp3[item.second] % mod; // 先乘后取模，不能用 *= dp3[] %mod
            } else {
                res = res * dp4[item.second] % mod; // 不然会变成: res * (dp3[] % mod)
            }
        }
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;
    auto res = s.countTexts("22233");
    cout << res << endl;
    assert(res == 8);
    res = s.countTexts("444444444444444444444444444444448888888888888888999999999999333333333333333366666666666666662222222222222222666666666666666633333333333333338888888888888888222222222222222244444444444444448888888888888222222222222222288888888888889999999999999999333333333444444664");
    cout << res << endl;
    assert(res == 537551452);
}