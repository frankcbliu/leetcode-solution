//给定一个单链表 L 的头节点 head ，单链表 L 表示为：
//
//
//L0 → L1 → … → Ln - 1 → Ln
//
//
// 请将其重新排列后变为：
//
//
//L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …
//
// 不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。
//
//
//
// 示例 1：
//
//
//
//
//输入：head = [1,2,3,4]
//输出：[1,4,2,3]
//
// 示例 2：
//
//
//
//
//输入：head = [1,2,3,4,5]
//输出：[1,5,2,4,3]
//
//
//
// 提示：
//
//
// 链表的长度范围为 [1, 5 * 10⁴]
// 1 <= node.val <= 1000
//
//
// Related Topics 栈 递归 链表 双指针 👍 1649 👎 0


#include "headers.h"

#include <memory>

//leetcode submit region begin(Prohibit modification and deletion)
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
  public:
  void reorderList(ListNode *head) {
    if (head->next == nullptr) return;
    // 找中点
    auto m = mid_node(head);
    // 反转后半部分, 中间截断
    ListNode *head2 = reverse(m);
    // 合并链表
    merge_list_node(head, head2);
  }

  ListNode *mid_node(ListNode *head) {
    ListNode *slow = head;
    ListNode *fast = head;
    while (fast && fast->next) {
      slow = slow->next;
      fast = fast->next->next;
    }
    return slow;
  }

  ListNode *reverse(ListNode *head) {
    ListNode *pre = nullptr;
    ListNode *cur = head;
    while (cur) {
      ListNode *nxt = cur->next;
      cur->next = pre;
      pre = cur;
      cur = nxt;
    }
    return pre;
  }

  // 合并 l1 和 l2
  void merge_list_node(ListNode *l1, ListNode *l2) {
    while (l2->next) {
      ListNode* nxt = l1->next;
      ListNode* nxt2 = l2->next;
      l1->next = l2;
      l2->next = nxt;
      l1 = nxt;
      l2 = nxt2;
    }
  }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
  Solution s;
  ListNode l1(vector<int>{1, 2, 3, 4, 5});
  ListNode l2(vector<int>{5, 4});
  // s.merge_list_node(&l1, &l2);
  // showListNode(&l1);
  // showListNode(&l2);

  auto m = s.mid_node(&l1);
  cout << "mid: " <<  m->val << endl;
  // showListNode(s.reverse(&l1));
  s.reorderList(&l1);
  showListNode(&l1);
}