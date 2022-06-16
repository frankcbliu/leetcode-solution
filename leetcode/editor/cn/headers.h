//
// Created by 菜饼 on 2022/4/16.
//

#ifndef LEETCODE_HEADERS_H
#define LEETCODE_HEADERS_H

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <queue>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode* next) : val(x), next(next) {}

    // 通过数组生成链表
    ListNode(vector<int> nums) {
      if (nums.empty()) {
        return;
      }
      // 初始化第一个节点
      val = nums[0];
      ListNode* tmp = new ListNode();
      for (int i = 1; i < nums.size(); ++i) {
        tmp->next = new ListNode(nums[i]);
        // 将第 2 个节点放回 next
        if (i == 1) next = tmp->next;
        tmp = tmp->next;
      }
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

// 遍历输出数组
template<typename T>
void showVectorLine(vector<T> arr) {
  for (int i = 0; i < arr.size(); ++i) {
    cout << arr[i] << endl;
  }
  cout << endl;
}

// 遍历输出二维数组数组
template<typename T>
void showVector2Line(vector<vector<T>> arr) {
  for (int i = 0; i < arr.size(); ++i) {
    for (int j = 0; j < arr[i].size(); ++j) {
      cout << arr[i][j] << endl;
    }
    cout << endl;
  }
  cout << endl;
}


// 遍历输出单链表
void showListNode(ListNode* list) {
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

#endif //LEETCODE_HEADERS_H
