//某公司组织架构以二叉搜索树形式记录，节点值为处于该职位的员工编号。请返回第 cnt 大的员工编号。
//
//
//
// 示例 1：
//
//
//
//
//输入：root = [7, 3, 9, 1, 5], cnt = 2
//       7
//      / \
//     3   9
//    / \
//   1   5
//输出：7
//
//
// 示例 2：
//
//
//
//
//输入: root = [10, 5, 15, 2, 7, null, 20, 1, null, 6, 8], cnt = 4
//       10
//      / \
//     5   15
//    / \    \
//   2   7    20
//  /   / \ 
// 1   6   8
//输出: 8
//
//
//
// 提示：
//
//
// 1 ≤ cnt ≤ 二叉搜索树元素个数
//
//
//
//
// Related Topics 树 深度优先搜索 二叉搜索树 二叉树 👍 425 👎 0


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
  int k = 0;
  int res = 0;

  int findTargetNode(TreeNode *root, int cnt) {
    if (root == nullptr) return 0;

    inorder(root, cnt);

    return res;
  }

  void inorder(TreeNode *root, int cnt) {
    if (root == nullptr) return;

    // 正常中序: 左中右
    // 逆向中序: 右中左

    inorder(root->right, cnt);

    ++k;
    if (k == cnt) {
      res = root->val;
    }

    inorder(root->left, cnt);
  }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
  Solution s;
  vector<int> arr{7, 1, 5, 3, 6, 4};
  auto res = s.twoSum(arr, 11);
  showVector(res);
}