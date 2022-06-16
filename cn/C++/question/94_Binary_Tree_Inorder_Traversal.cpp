// @algorithm @lc id=94 lang=cpp
// @title binary-tree-inorder-traversal

#include <iostream>
#include <vector>
#include <string>
#include "algm/algm.h"
using namespace std;
// @test([1,null,2,3])=[1,3,2]
// @test([])=[]
// @test([1])=[1]
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
 public:
  vector<int> inorderTraversal(TreeNode* root) {
    // 解法2: 迭代法
    vector<int> result;
    stack<TreeNode*> store;
    store.push(root);
    TreeNode* p = root;
    while (!store.empty()) {
      // 取栈顶
      p = store.top();
      if (p->right != nullptr) {
        store.push(p->right);
        continue;
      }

      result.push_back(p->val);
      store.pop();

      
    }
    return result;
  }
};