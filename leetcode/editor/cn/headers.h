//
// Created by 菜饼 on 2022/4/16.
//

#ifndef LEETCODE_HEADERS_H
#define LEETCODE_HEADERS_H

#include <algorithm>
#include <bitset>
#include <iostream>
#include <queue>
#include <random>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

struct Node {
  int val;
  Node *next;
  Node *random;

  Node() : val(0), next(nullptr), random(nullptr) {}
  Node(int x) : val(x), next(nullptr), random(nullptr) {}
  Node(int x, Node *nxt) : val(x), next(nxt), random(nullptr) {}

  // 通过数组生成链表
  Node(const vector<int> &nums) {
    if (nums.empty()) return;

    val = nums[0];
    Node *pre = this;
    for (int i = 1; i < nums.size(); i++) {
      pre->next = new Node(nums[i]);
      pre = pre->next;
    }
  }
};

struct ListNode {
  int val;
  ListNode *next;

  ListNode() : val(0), next(nullptr) {}

  ListNode(int x) : val(x), next(nullptr) {}

  ListNode(int x, ListNode *next) : val(x), next(next) {}

  // 通过数组生成链表
  explicit ListNode(const vector<int> &nums) {
    if (nums.empty()) return;

    val = nums[0];
    ListNode *pre = this;
    for (int i = 1; i < nums.size(); i++) {
      pre->next = new ListNode(nums[i]);
      pre = pre->next;
    }
  }
};

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  TreeNode *ArrayTree(vector<int> nums, int i, int n) {
    TreeNode *p = nullptr;
    if (i > n || nums.empty() || nums[i] == -1) {
      return p;
    }
    if (i < n) {
      p = new TreeNode();
      p->val = nums[i];
      p->left = ArrayTree(nums, 2 * i + 1, n);
      p->right = ArrayTree(nums, 2 * i + 2, n);
    }
    return p;
  }
  TreeNode(vector<int> nums) {
    if (nums.empty())
      return;
    TreeNode *data = ArrayTree(nums, 0, nums.size());
    this->val = data->val;
    this->left = data->left;
    this->right = data->right;
  }
};

// 遍历输出数组
template<typename T>
void showVector(vector<T> arr) {
  for (int i = 0; i < arr.size(); ++i) {
    cout << arr[i] << " ";
  }
  cout << endl;
}

void showVector(vector<int> arr) {
  for (int i = 0; i < arr.size(); ++i) {
    cout << arr[i] << " ";
  }
  cout << endl;
}

// 遍历输出二维数组数组
template<typename T>
void showVector2(vector<vector<T>> arr) {
  for (int i = 0; i < arr.size(); ++i) {
    for (int j = 0; j < arr[i].size(); ++j) {
      cout << arr[i][j] << " ";
    }
    cout << endl;
  }
  cout << endl;
}

// 遍历输出单链表
void showListNode(ListNode *list) {
  cout << "list: ";
  while (list) {
    cout << list->val << " ";
    list = list->next;
  }
  cout << endl;
}

void showListNode(ListNode list) {
  showListNode(&list);
}

int get_val(Node *node) {
  if (node == nullptr) return -1;
  return node->val;
}

void showNode(Node *list) {
  cout << "list: ";
  while (list) {
    cout << list->val << "(" << get_val(list->random) << ") ";
    list = list->next;
  }
  cout << endl;
}

void showNode(Node list) {
  showNode(&list);
}

// 把整型转为二进制
std::string int_to_bit_str(int i) {
  std::bitset<8> bits(i);
  return bits.to_string();
}

int random_l_r(int l, int r) {
  static std::random_device rd;
  static std::mt19937 gen(rd());
  std::uniform_int_distribution<> dis(l, r);
  return dis(gen);
}

#endif//LEETCODE_HEADERS_H
