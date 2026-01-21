//给定一个二叉树的 根节点 root，想象自己站在它的右侧，按照从顶部到底部的顺序，返回从右侧所能看到的节点值。
//
//
//
// 示例 1：
//
//
// 输入：root = [1,2,3,null,5,null,4]
//
//
// 输出：[1,3,4]
//
// 解释：
//
//
//
// 示例 2：
//
//
// 输入：root = [1,2,3,4,null,null,null,5]
//
//
// 输出：[1,3,4,5]
//
// 解释：
//
//
//
// 示例 3：
//
//
// 输入：root = [1,null,3]
//
//
// 输出：[1,3]
//
// 示例 4：
//
//
// 输入：root = []
//
//
// 输出：[]
//
//
//
// 提示:
//
//
// 二叉树的节点个数的范围是 [0,100]
//
// -100 <= Node.val <= 100
//
//
// Related Topics 树 深度优先搜索 广度优先搜索 二叉树 👍 1273 👎 0


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
  // 层序遍历，每一层最后一个
  vector<int> rightSideViewBFS(TreeNode *root) {
    if (root == nullptr) return {};

    vector<int> res;

    queue<TreeNode *> q;
    q.push(root);

    while (!q.empty()) {
      int level_size = q.size();

      for (int i = 0; i < level_size; ++i) {
        auto front = q.front();
        q.pop();

        if (front->left) q.push(front->left);
        if (front->right) q.push(front->right);
        // 只填最后一个值
        if (i == level_size - 1) res.push_back(front->val);
      }
    }
    return res;
  }

  vector<int> dfs_res;
  // 递归解法
  vector<int> rightSideView(TreeNode *root) {
    dfs(root, 0);
    return dfs_res;
  }

  void dfs(TreeNode *root, int depth) {
    if (root == nullptr) return;

    if (dfs_res.size() == depth) {
      dfs_res.push_back(root->val);
    }

    dfs(root->right, depth + 1);
    dfs(root->left, depth + 1);
  }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
  Solution s;
  vector<int> arr{7, 1, 5, 3, 6, 4};
  auto res = s.twoSum(arr, 11);
  showVector(res);
}