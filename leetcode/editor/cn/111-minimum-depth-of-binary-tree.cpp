//给定一个二叉树，找出其最小深度。
//
// 最小深度是从根节点到最近叶子节点的最短路径上的节点数量。
//
// 说明：叶子节点是指没有子节点的节点。
//
//
//
// 示例 1：
//
//
//输入：root = [3,9,20,null,null,15,7]
//输出：2
//
//
// 示例 2：
//
//
//输入：root = [2,null,3,null,4,null,5,null,6]
//输出：5
//
//
//
//
// 提示：
//
//
// 树中节点数的范围在 [0, 10⁵] 内
// -1000 <= Node.val <= 1000
//
//
// Related Topics 树 深度优先搜索 广度优先搜索 二叉树 👍 1320 👎 0


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
  // 需要列出所有情况
  // 叶子节点/只有左子节点/只有右子节点/两边都有
  int minDepthDFS(TreeNode *root) {
    if (root == nullptr) return 0;
    if (root->left == nullptr && root->right == nullptr) return 1;
    if (root->left == nullptr) return minDepth(root->right) + 1;
    if (root->right == nullptr) return minDepth(root->left) + 1;
    return min(minDepth(root->left), minDepth(root->right)) + 1;
  }

  // BFS做法，需要涉及队列
  int minDepthBFS(TreeNode *root) {
    if (root == nullptr) return 0;

    // 还有一个办法，把 depth 也打到 queue 里，变成 queue<pair<TreeNode*, int>>
    // 这样就不用两层循环
    queue<TreeNode *> q;
    q.push(root);
    int depth = 1;

    while (!q.empty()) {
      int level_size = q.size();
      for (int i = 0; i < level_size; ++i) {
        TreeNode *node = q.front();
        q.pop();

        // 找到叶子节点
        if (node->left == nullptr && node->right == nullptr) {
          return depth;
        }

        if (node->left) q.push(node->left);
        if (node->right) q.push(node->right);
      }
      depth++;
    }
    return depth;
  }

  int minDepth(TreeNode *root) {
    // 边界条件
    if (root == nullptr) return 0;
    // 核心逻辑
    // 1. 构建队列，填充root节点
    queue<pair<TreeNode * /*子树*/, int /*层级*/>> q;
    q.push({root, 1});
    // 2. 循环直到队列非空，按层填充子节点
    while (!q.empty()) {
      // 3. 取出队列头结点
      auto front = q.front();
      q.pop();
      int depth = front.second;
      // 4. 计算是否叶子节点，如果是，说明遇到最小深度，直接返回
      if (front.first->left == nullptr && front.first->right == nullptr) {
        return depth;
      }
      // 5. 把左子节点和右子节点填入队列中
      if (front.first->left) q.push(make_pair(front.first->left, depth+1));
      if (front.first->right) q.push(make_pair(front.first->right, depth+1));
    }
    return 0;
  }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
  Solution s;
  vector<int> arr{7, 1, 5, 3, 6, 4};
  auto res = s.twoSum(arr, 11);
  showVector(res);
}