// @algorithm @lc id=102 lang=cpp
// @title binary-tree-level-order-traversal

#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include "algm/algm.h"
using namespace std;
// @test([3,9,20,null,null,15,7])=[[3],[9,20],[15,7]]
// @test([1])=[[1]]
// @test([])=[]
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
  vector<vector<int>> levelOrder(TreeNode* root) {
    queue<TreeNode*> p;
    queue<TreeNode*> q;
    p.push(root);
    vector<vector<int>> res;
    vector<int> tmp;
    while (!p.empty()) {
      TreeNode* first = p.front();
      tmp.push_back(first->val);
      p.pop();
      if (first->left) {
        q.push(first->left);
      }
      if (first->right) {
        q.push(first->right);
      }
      if (p.empty()) {
        res.push_back(vector<int>(tmp));
        p.swap(q);
        tmp.clear();
      }
    }
    return res;
  }
};