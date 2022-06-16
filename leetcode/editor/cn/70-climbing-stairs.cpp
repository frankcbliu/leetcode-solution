//假设你正在爬楼梯。需要 n 阶你才能到达楼顶。 
//
// 每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？ 
//
// 
//
// 示例 1： 
//
// 
//输入：n = 2
//输出：2
//解释：有两种方法可以爬到楼顶。
//1. 1 阶 + 1 阶
//2. 2 阶 
//
// 示例 2： 
//
// 
//输入：n = 3
//输出：3
//解释：有三种方法可以爬到楼顶。
//1. 1 阶 + 1 阶 + 1 阶
//2. 1 阶 + 2 阶
//3. 2 阶 + 1 阶
// 
//
// 
//
// 提示： 
//
// 
// 1 <= n <= 45 
// 
// Related Topics 记忆化搜索 数学 动态规划 👍 2375 👎 0


#include "headers.h"

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int climbStairs(int n) {
//      vector<int> arr;
//      arr.reserve(n + 1);
//      for (int i = 0; i <= n; ++i) {
//        if (i <= 2)
//          arr.push_back(i);
//        else
//          arr.push_back(arr[i - 1] + arr[i - 2]);
//      }
//      return arr[n];

      // 用两个变量来存储
      int a = 0, b = 1;
      for (int i = 2; i <= n; ++i) {
        int tmp = a + b;
        a = b;
        b = tmp;
      }
      return a + b;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
  Solution s;
  cout << s.climbStairs(3) << endl;
  cout << s.climbStairs(4) << endl;
}