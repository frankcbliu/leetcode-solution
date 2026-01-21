//给定一个包含非负整数的 m x n 网格 grid ，请找出一条从左上角到右下角的路径，使得路径上的数字总和为最小。
//
// 说明：每次只能向下或者向右移动一步。
//
//
//
// 示例 1：
//
//
//输入：grid = [[1,3,1],[1,5,1],[4,2,1]]
//输出：7
//解释：因为路径 1→3→1→1→1 的总和最小。
//
//
// 示例 2：
//
//
//输入：grid = [[1,2,3],[4,5,6]]
//输出：12
//
//
//
//
// 提示：
//
//
// m == grid.length
// n == grid[i].length
// 1 <= m, n <= 200
// 0 <= grid[i][j] <= 200
//
//
// Related Topics 数组 动态规划 矩阵 👍 1894 👎 0


#include "headers.h"

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
  public:
  int minPathSum(vector<vector<int>> &grid) {
    int m = grid.size();
    int n = grid[0].size();

    vector<vector<int>> sum(m, vector<int>(n, 0));

    sum[0][0] = grid[0][0];
    // 第一列
    for (int i = 1; i < m; ++i) {
      sum[i][0] = sum[i - 1][0] + grid[i][0];
    }
    // 第一行
    for (int i = 1; i < n; ++i) {
      sum[0][i] = sum[0][i - 1] + grid[0][i];
    }

    // 遍历全部
    for (int i = 1; i < m; ++i) {
      for (int j = 1; j < n; ++j) {
        sum[i][j] = min(sum[i - 1][j], sum[i][j - 1]) + grid[i][j];
      }
    }
    return sum[m - 1][n - 1];
  }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
  Solution s;
  vector<int> arr{7, 1, 5, 3, 6, 4};
  auto res = s.twoSum(arr, 11);
  showVector(res);
}