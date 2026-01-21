//二叉树中的 路径 被定义为一条节点序列，序列中每对相邻节点之间都存在一条边。同一个节点在一条路径序列中 至多出现一次 。该路径 至少包含一个 节点，且不一定
//经过根节点。
//
// 路径和 是路径中各节点值的总和。
//
// 给你一个二叉树的根节点 root ，返回其 最大路径和 。
//
//
//
// 示例 1：
//
//
//输入：root = [1,2,3]
//输出：6
//解释：最优路径是 2 -> 1 -> 3 ，路径和为 2 + 1 + 3 = 6
//
// 示例 2：
//
//
//输入：root = [-10,9,20,null,null,15,7]
//输出：42
//解释：最优路径是 15 -> 20 -> 7 ，路径和为 15 + 20 + 7 = 42
//
//
//
//
// 提示：
//
//
// 树中节点数目范围是 [1, 3 * 10⁴]
// -1000 <= Node.val <= 1000
//
//
// Related Topics 树 深度优先搜索 动态规划 二叉树 👍 2519 👎 0


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
  int max_sum = INT_MIN;
  int maxPathSum(TreeNode *root) {
    dfs(root);
    return max_sum;
  }
  // 计算以当前节点，向下延伸的路径的最大贡献度，只可能有三种情况(节点自己，节点+左子节点，节点+右子节点)
  int dfs(TreeNode *root) {
    if (root == nullptr) return 0;

    // 最大贡献度
    int left = max(dfs(root->left), 0);
    int right = max(dfs(root->right), 0);

    // 计算最大路径和
    int all = root->val + left + right;
    max_sum = max(max_sum, all);

    return root->val + max(left, right);
  }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
  Solution s;
  vector<int> arr{7, 1, 5, 3, 6, 4};
  auto res = s.twoSum(arr, 11);
  showVector(res);
}