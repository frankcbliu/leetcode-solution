//将两个升序链表合并为一个新的 升序 链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。
//
//
//
// 示例 1：
//
//
//输入：l1 = [1,2,4], l2 = [1,3,4]
//输出：[1,1,2,3,4,4]
//
//
// 示例 2：
//
//
//输入：l1 = [], l2 = []
//输出：[]
//
//
// 示例 3：
//
//
//输入：l1 = [], l2 = [0]
//输出：[0]
//
//
//
//
// 提示：
//
//
// 两个链表的节点数目范围是 [0, 50]
// -100 <= Node.val <= 100
// l1 和 l2 均按 非递减顺序 排列
//
//
// Related Topics 递归 链表 👍 3950 👎 0


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
    // dummy -> 1 -> 2 -> 3(cur)
    //    null(p)
    //    4(q) -> 6

    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {
        ListNode dummy(0);
        ListNode *cur = &dummy;
        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val <= list2->val) {
                cur->next = list1;
                list1 = list1->next;
            } else {
                cur->next = list2;
                list2 = list2->next;
            }
            // 注意，每一轮 cur 要往后挪动
            cur = cur->next;
        }
        if (list1 == nullptr) {
            cur->next = list2;
        } else if (list2 == nullptr) {
            cur->next = list1;
        }
        return dummy.next;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;
    ListNode listA(vector<int>{1, 2, 4});
    ListNode listB(vector<int>{1, 3, 4});

    auto res = s.mergeTwoLists(&listA, &listB);
    showListNode(res);
}