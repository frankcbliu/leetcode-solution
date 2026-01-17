//给你链表的头节点 head ，每 k 个节点一组进行翻转，请你返回修改后的链表。
//
// k 是一个正整数，它的值小于或等于链表的长度。如果节点总数不是 k 的整数倍，那么请将最后剩余的节点保持原有顺序。
//
// 你不能只是单纯的改变节点内部的值，而是需要实际进行节点交换。
//
//
//
// 示例 1：
//
//
//输入：head = [1,2,3,4,5], k = 2
//输出：[2,1,4,3,5]
//
//
// 示例 2：
//
//
//
//
//输入：head = [1,2,3,4,5], k = 3
//输出：[3,2,1,4,5]
//
//
//
//提示：
//
//
// 链表中的节点数目为 n
// 1 <= k <= n <= 5000
// 0 <= Node.val <= 1000
//
//
//
//
// 进阶：你可以设计一个只用 O(1) 额外内存空间的算法解决此问题吗？
//
//
//
//
// Related Topics 递归 链表 👍 2717 👎 0


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
    ListNode *reverseKGroup(ListNode *head, int k) {
        if (k < 2) {// 不翻转
            return head;
        }
        // 构建 left 节点
        ListNode *left = new ListNode();
        left->next = head;
        // 构建 cur 节点
        ListNode *cur = head;
        int cnt = 0;
        while (cur != nullptr) {
            ++cnt;
            // 取模， 比如 k = 3, cnt=1, 1%k=1; cnt=2, k%2=2; cnt=3, k%3=0,符合条件
            if (cnt % k == 0) {
                left = reverse(left, left->next, cur, cur->next);
                // 首次翻转时，上面 left = begin = head, 因此, head 需要更新为 cur, 而后续不用
                head = (head == left ? cur : head);
                cur = left;
            }
            cur = cur->next;
        }
        return head;
    }


    // 翻转 left -> begin -> ... -> end -> right
    // 变成 left -> end -> ... -> begin -> right
    // 注意，返回的并不是翻转后的头节点，而是翻转后的尾节点
    ListNode *reverse(ListNode *left, ListNode *begin, ListNode *end, ListNode *right) {
        ListNode *prev = left;
        ListNode *cur = begin;
        while (cur != right) {
            ListNode *tmp = cur->next;
            cur->next = prev;
            prev = cur;
            cur = tmp;
        }
        left->next = end;
        begin->next = right;
        return begin;
    }

    // 解法2：灵府山
    ListNode *reverseKGroup2(ListNode *head, int k) {
        // 计算链表长度
        int n = 0;
        ListNode *cur = head;
        while (cur != nullptr) {
            n++;
            cur = cur->next;
        }
        // 哨兵节点
        ListNode dummy(0);
        dummy.next = head;
        ListNode *p0 = &dummy;
        ListNode *pre = nullptr;
        cur = p0->next;
        // K个一组进行反转, 不足k个的不反转
        while (n >= k) {
            n -= k;
            for (int i = 0; i < k; i++) {
                ListNode *nxt = cur->next;
                cur->next = pre;
                pre = cur;
                cur = nxt;
            }
            ListNode *nxt2 = p0->next;
            p0->next->next = cur;
            p0->next = pre;
            p0 = nxt2;
        }
        return dummy.next;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;
    vector<int> arr{7, 1, 5, 3, 6, 4};
    auto res = s.twoSum(arr, 11);
    showVector(res);
}