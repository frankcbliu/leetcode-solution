//
// Created by 菜饼 on 2022/4/16.
//

#ifndef LEETCODE_HEADERS_H
#define LEETCODE_HEADERS_H

#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}

    // 通过数组生成链表
    ListNode(vector<int> nums) {
        if (nums.empty()) {
            return;
        }
        // 初始化第一个节点
        val = nums[0];
        ListNode *tmp = new ListNode();
        for (int i = 1; i < nums.size(); ++i) {
            tmp->next = new ListNode(nums[i]);
            // 将第 2 个节点放回 next
            if (i == 1) next = tmp->next;
            tmp = tmp->next;
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
void showVector2(vector<vector<int>> arr) {
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

#endif//LEETCODE_HEADERS_H
