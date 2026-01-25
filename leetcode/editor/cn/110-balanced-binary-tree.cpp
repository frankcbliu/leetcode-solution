//给定一个二叉树，判断它是否是 平衡二叉树
//
//
//
// 示例 1：
//
//
//输入：root = [3,9,20,null,null,15,7]
//输出：true
//
//
// 示例 2：
//
//
//输入：root = [1,2,2,3,3,null,null,4,4]
//输出：false
//
//
// 示例 3：
//
//
//输入：root = []
//输出：true
//
//
//
//
// 提示：
//
//
// 树中的节点数在范围 [0, 5000] 内
// -10⁴ <= Node.val <= 10⁴
//
//
// Related Topics 树 深度优先搜索 二叉树 👍 1664 👎 0


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
  int getHeight(TreeNode *root) {
    if (root == nullptr) return 0;

    int left = getHeight(root->left);
    int right = getHeight(root->right);
    if (left == -1 || right == -1 ||
        abs(left - right) > 1) return -1;
    return max(left, right) + 1;
  }

  bool isBalanced(TreeNode *root) {
    if (root == nullptr) return true;
    return getHeight(root) >= 0;
  }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
  Solution s;
  vector<int> arr{1, 2, 2, 3, -1, -1, 3, 4, -1, -1, -1, -1, -1, -1, 4};
  TreeNode root(arr);
  // s.inOrder(&root);// 4 3 2 1 2 3 4
  cout << endl;
  auto res = s.isBalanced(&root);
  cout << res << endl;
}