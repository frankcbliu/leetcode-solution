//按照国际象棋的规则，皇后可以攻击与之处在同一行或同一列或同一斜线上的棋子。 
//
// n 皇后问题 研究的是如何将 n 个皇后放置在 n×n 的棋盘上，并且使皇后彼此之间不能相互攻击。 
//
// 给你一个整数 n ，返回所有不同的 n 皇后问题 的解决方案。 
//
// 
// 
// 每一种解法包含一个不同的 n 皇后问题 的棋子放置方案，该方案中 'Q' 和 '.' 分别代表了皇后和空位。 
//
// 
//
// 示例 1： 
//
// 
//输入：n = 4
//输出：[[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
//解释：如上图所示，4 皇后问题存在两个不同的解法。
// 
//
// 示例 2： 
//
// 
//输入：n = 1
//输出：[["Q"]]
// 
//
// 
//
// 提示： 
//
// 
// 1 <= n <= 9 
// 
// 
// 
// Related Topics 数组 回溯 👍 1386 👎 0


#include "headers.h"

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
private:
    vector<vector<string>> res;

    bool check(int i, int j) {
      // 检查列
      for (int col = 0; col < i; ++col) {
        if (board[i][col] == 'Q') return false;
      }

      // 检查行
      for (int row = 0; row < i; ++row) {
        if (board[row][j] == 'Q') return false;
      }

      // 检查左上斜方
      for (int row = i - 1, col = j - 1; row >= 0 && col >= 0; row--, col--) {
        if (board[row][col] == 'Q') return false;
      }

      // 检查右上斜方
      for (int row = i - 1, col = j + 1; row >= 0 && col < N; row--, col++) {
        if (board[row][col] == 'Q') return false;
      }

      return true;
    }

    void solve(int row) {
      if (row == N) {
        res.push_back(board);
        return;
      }

      for (int col = 0; col < N; ++col) {
        if (check(row, col)) {
          board[row][col] = 'Q';
          solve(row + 1);
          board[row][col] = '.';
        }
      }
    }

public:
    vector<string> board;
    int N;

    vector<vector<string>> solveNQueens(int n) {
      N = n;
      // init
      for (int i = 0; i < n; ++i) {
        string row = "";
        for (int j = 0; j < n; ++j) {
          row += ".";
        }
        board.push_back(row);
      }
      // DFS
      solve(0);
      return res;
    }

};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
  Solution s;
  int n = 4;
  auto res = s.solveNQueens(n);
  showVector2Line(res);
}