//给你一个单链表的头节点 head ，请你判断该链表是否为回文链表。如果是，返回 true ；否则，返回 false 。
//
//
//
// 示例 1：
//
//
//输入：head = [1,2,2,1]
//输出：true
//
//
// 示例 2：
//
//
//输入：head = [1,2]
//输出：false
//
//
//
//
// 提示：
//
//
// 链表中节点数目在范围[1, 10⁵] 内
// 0 <= Node.val <= 9
//
//
//
//
// 进阶：你能否用 O(n) 时间复杂度和 O(1) 空间复杂度解决此题？
//
// Related Topics 栈 递归 链表 双指针 👍 2180 👎 0


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
  bool isPalindrome(ListNode *head) {
    if (!head->next) return true;
    // 快慢指针定位中点
    auto arr = middle_and_pre(head);
    ListNode *pre_head2 = arr[0];
    ListNode *head2 = reverse(arr[1]);
    bool is_pal = true;
    // 中点反转后对比
    while (head2 != nullptr) {
      if (head->val != head2->val) {
        is_pal = false;
        break;
      }
      head = head->next;
      head2 = head2->next;
    }
    // 复原
    pre_head2->next = reverse(head2);
    return is_pal;
  }

  vector<ListNode *> middle_and_pre(ListNode *head) {
    ListNode *slow = head;
    ListNode *fast = head;
    ListNode *pre = nullptr;
    while (fast && fast->next) {
      pre = slow;
      slow = slow->next;
      fast = fast->next->next;
    }
    return {pre, slow};
  }

  // 获取链表中点
  ListNode *middle(ListNode *head) {
    ListNode *slow = head;
    ListNode *fast = head;
    while (fast && fast->next) {
      slow = slow->next;
      fast = fast->next->next;
    }
    return slow;
  }

  // 反转链表
  ListNode *reverse(ListNode *head) {
    ListNode *pre = nullptr;
    ListNode *cur = head;
    while (cur != nullptr) {
      ListNode *nxt = cur->next;
      cur->next = pre;
      pre = cur;
      cur = nxt;
    }
    return pre;
  }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
  Solution s;
  ListNode l1(vector<int>{1, 2, 3, 1});
  auto arr = s.middle_and_pre(&l1);
  ListNode *pre_head2 = arr[0];
  ListNode *head2 = arr[1];
  showListNode(pre_head2);
  showListNode(head2);
  auto res = s.isPalindrome(&l1);
  cout << res;
}