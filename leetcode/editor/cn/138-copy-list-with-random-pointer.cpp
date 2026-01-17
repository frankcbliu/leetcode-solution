//给你一个长度为 n 的链表，每个节点包含一个额外增加的随机指针 random ，该指针可以指向链表中的任何节点或空节点。
//
// 构造这个链表的 深拷贝。 深拷贝应该正好由 n 个 全新 节点组成，其中每个新节点的值都设为其对应的原节点的值。新节点的 next 指针和 random
//指针也都应指向复制链表中的新节点，并使原链表和复制链表中的这些指针能够表示相同的链表状态。复制链表中的指针都不应指向原链表中的节点 。
//
// 例如，如果原链表中有 X 和 Y 两个节点，其中 X.random --> Y 。那么在复制链表中对应的两个节点 x 和 y ，同样有 x.random
//--> y 。
//
// 返回复制链表的头节点。
//
// 用一个由 n 个节点组成的链表来表示输入/输出中的链表。每个节点用一个 [val, random_index] 表示：
//
//
// val：一个表示 Node.val 的整数。
// random_index：随机指针指向的节点索引（范围从 0 到 n-1）；如果不指向任何节点，则为 null 。
//
//
// 你的代码 只 接受原链表的头节点 head 作为传入参数。
//
//
//
// 示例 1：
//
//
//
//
//输入：head = [[7,null],[13,0],[11,4],[10,2],[1,0]]
//输出：[[7,null],[13,0],[11,4],[10,2],[1,0]]
//
//
// 示例 2：
//
//
//
//
//输入：head = [[1,1],[2,1]]
//输出：[[1,1],[2,1]]
//
//
// 示例 3：
//
//
//
//
//输入：head = [[3,null],[3,0],[3,null]]
//输出：[[3,null],[3,0],[3,null]]
//
//
//
//
// 提示：
//
//
// 0 <= n <= 1000
//
// -10⁴ <= Node.val <= 10⁴
// Node.random 为 null 或指向链表中的节点。
//
//
//
//
// Related Topics 哈希表 链表 👍 1728 👎 0


#include "headers.h"

//leetcode submit region begin(Prohibit modification and deletion)
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
  public:
  Node *copyRandomList(Node *head) {
    if (head == nullptr) return nullptr;

    // 复制链表，并把节点插在原节点后面
    Node *cur = head;
    while (cur != nullptr) {
      Node *nxt = cur->next;
      cur->next = new Node(cur->val, cur->next);
      cur = nxt;
    }

    // 复制随机指针
    cur = head;
    while (cur != nullptr) {
      cur->next->random = cur->random ? cur->random->next : nullptr;
      cur = cur->next->next;
    }
    // 分离链表
    Node dummy(0);
    Node *tail = &dummy;
    cur = head;
    while (cur != nullptr) {
      tail->next = cur->next;
      cur->next = tail->next->next;
      cur = cur->next;
      tail = tail->next;
    }
    return head;
  }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
  Solution s;
  Node l1(vector<int>{1, 2, 3, 4, 5, 6, 7});
  vector<Node *> m1;
  Node *cur = &l1;
  while (cur != nullptr) {
    m1.push_back(cur);
    cur = cur->next;
  }
  cur = &l1;
  while (cur != nullptr) {
    cur->random = m1[random_l_r(0, m1.size() - 1)];
    cur = cur->next;
  }

  showNode(l1);
  auto arr = s.copyRandomList(&l1);
  showNode(arr);
}