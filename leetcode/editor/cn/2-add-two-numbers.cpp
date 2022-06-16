//给你两个 非空 的链表，表示两个非负的整数。它们每位数字都是按照 逆序 的方式存储的，并且每个节点只能存储 一位 数字。 
//
// 请你将两个数相加，并以相同形式返回一个表示和的链表。 
//
// 你可以假设除了数字 0 之外，这两个数都不会以 0 开头。 
//
// 
//
// 示例 1： 
//
// 
//输入：l1 = [2,4,3], l2 = [5,6,4]
//输出：[7,0,8]
//解释：342 + 465 = 807.
// 
//
// 示例 2： 
//
// 
//输入：l1 = [0], l2 = [0]
//输出：[0]
// 
//
// 示例 3： 
//
// 
//输入：l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
//输出：[8,9,9,9,0,0,0,1]
// 
//
// 
//
// 提示： 
//
// 
// 每个链表中的节点数在范围 [1, 100] 内 
// 0 <= Node.val <= 9 
// 题目数据保证列表表示的数字不含前导零 
// 
// Related Topics 递归 链表 数学 👍 7909 👎 0


#include "headers.h"

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
      // 头指针
      ListNode* head = new ListNode();
      ListNode* t = head;
      bool carry = false;  // 进位标志
      while (l1 != nullptr || l2 != nullptr) {
        int sum = 0;  // 计算每一位的和
        if (l1 != nullptr) {
          sum += l1->val;
          l1 = l1->next;
        }
        if (l2 != nullptr) {
          sum += l2->val;
          l2 = l2->next;
        }
        if (carry) sum++;
        t->next = new ListNode(sum % 10);
        t = t->next;
        carry = sum > 9;
      }
      // 末位进位需要新增节点
      if (carry) {
        t->next = new ListNode(1);
      }
      return head->next;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
  Solution s;
  vector<int> arr{3, 1, 7, 2};
  ListNode* l1 = new ListNode({2, 4, 3});
  ListNode* l2 = new ListNode({5, 6, 4});
  showListNode(s.addTwoNumbers(l1, l2));

  l1 = new ListNode({0});
  l2 = new ListNode({0});
  showListNode(s.addTwoNumbers(l1, l2));

  l1 = new ListNode({9, 9, 9, 9, 9, 9, 9});
  l2 = new ListNode({9, 9, 9, 9});
  showListNode(s.addTwoNumbers(l1, l2));
}