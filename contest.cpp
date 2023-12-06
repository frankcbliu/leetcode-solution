/**
* 临时测试使用
*/

#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    explicit ListNode(int val) : val(val), next(nullptr) {}
};

int main() {
    ListNode head = ListNode(1);
    head.next = new ListNode(2);

    cout << head.val;
    cout << head.next->val;
    return 0;
}