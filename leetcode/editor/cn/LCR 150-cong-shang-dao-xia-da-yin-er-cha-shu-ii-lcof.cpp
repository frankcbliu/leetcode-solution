//一棵圣诞树记作根节点为 root 的二叉树，节点值为该位置装饰彩灯的颜色编号。请按照从左到右的顺序返回每一层彩灯编号，每一层的结果记录于一行。
//
//
//
// 示例 1：
//
//
//
//
//输入：root = [8,17,21,18,null,null,6]
//输出：[[8],[17,21],[18,6]]
//
//
// 提示：
//
//
// 节点总数 <= 1000
//
//
// 注意：本题与主站 102 题相同：https://leetcode.cn/problems/binary-tree-level-order-
//traversal/
//
//
//
// Related Topics 树 广度优先搜索 二叉树 👍 324 👎 0


#include "headers.h"

//leetcode submit region begin(Prohibit modification and deletion)
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
  public:
  // BFS，需要记录层数
  vector<vector<int>> decorateRecord(TreeNode *root) {
    if (root == nullptr) return {};
    vector<vector<int>> res;

    queue<TreeNode *> q;
    q.push(root);

    while (!q.empty()) {
      int level_size = q.size();

      vector<int> level_res;
      for (int i = 0; i < level_size; ++i) {
        auto front = q.front();
        q.pop();

        level_res.push_back(front->val);

        if (front->left) q.push(front->left);
        if (front->right) q.push(front->right);
      }
      res.push_back(level_res);
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