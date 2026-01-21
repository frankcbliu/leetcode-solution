//给你二叉树的根节点 root 和一个整数目标和 targetSum ，找出所有 从根节点到叶子节点 路径总和等于给定目标和的路径。
//
// 叶子节点 是指没有子节点的节点。
//
//
//
// 示例 1：
//
//
//
//
//输入：root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
//输出：[[5,4,11,2],[5,8,4,5]]
//
//
// 示例 2：
//
//
//
//
//输入：root = [1,2,3], targetSum = 5
//输出：[]
//
//
// 示例 3：
//
//
//输入：root = [1,2], targetSum = 0
//输出：[]
//
//
//
//
// 提示：
//
//
// 树中节点总数在范围 [0, 5000] 内
// -1000 <= Node.val <= 1000
// -1000 <= targetSum <= 1000
//
//
// 注意：本题与主站 113 题相同：https://leetcode.cn/problems/path-sum-ii/
//
//
//
// Related Topics 树 深度优先搜索 回溯 二叉树 👍 469 👎 0


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
  vector<vector<int>> res;
  vector<vector<int>> pathTarget(TreeNode *root, int target) {
    //  vector<int> path;
    //  dfs(root, target, path);
    dfs2(root, target, 0);
    return res;
  }

  // 直接使用 vector 传参，比较暴力
  void dfs(TreeNode *root, int target, vector<int> path) {
    if (root == nullptr) return;

    path.push_back(root->val);
    if (!root->left && !root->right && (root->val == target)) {
      res.push_back(path);
    }
    int new_target = target - root->val;
    if (root->left) dfs(root->left, new_target, path);
    if (root->right) dfs(root->right, new_target, path);
  }

  vector<int> paths;
  // 优化2: 外层记录 path，dfs 只传 sum
  void dfs2(TreeNode *root, int target, int sum) {
    if (root == nullptr) return;

    sum += root->val;
    paths.push_back(root->val);
    if (target == sum && !root->left && !root->right) {
      res.push_back(paths);
    }
    // 中左右，前序遍历
    if (root->left) dfs2(root->left, target, sum);
    if (root->right) dfs2(root->right, target, sum);

    paths.pop_back();
  }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
  Solution s;
  vector<int> arr{7, 1, 5, 3, 6, 4};
  auto res = s.twoSum(arr, 11);
  showVector(res);
}