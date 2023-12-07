//你可以选择使用单链表或者双链表，设计并实现自己的链表。
//
// 单链表中的节点应该具备两个属性：val 和 next 。val 是当前节点的值，next 是指向下一个节点的指针/引用。
//
// 如果是双向链表，则还需要属性 prev 以指示链表中的上一个节点。假设链表中的所有节点下标从 0 开始。
//
// 实现 MyLinkedList 类：
//
//
// MyLinkedList() 初始化 MyLinkedList 对象。
// int get(int index) 获取链表中下标为 index 的节点的值。如果下标无效，则返回 -1 。
// void addAtHead(int val) 将一个值为 val 的节点插入到链表中第一个元素之前。在插入完成后，新节点会成为链表的第一个节点。
// void addAtTail(int val) 将一个值为 val 的节点追加到链表中作为链表的最后一个元素。
// void addAtIndex(int index, int val) 将一个值为 val 的节点插入到链表中下标为 index 的节点之前。如果
//index 等于链表的长度，那么该节点会被追加到链表的末尾。如果 index 比长度更大，该节点将 不会插入 到链表中。
// void deleteAtIndex(int index) 如果下标有效，则删除链表中下标为 index 的节点。
//
//
//
//
// 示例：
//
//
//输入
//["MyLinkedList", "addAtHead", "addAtTail", "addAtIndex", "get",
//"deleteAtIndex", "get"]
//[[], [1], [3], [1, 2], [1], [1], [1]]
//输出
//[null, null, null, null, 2, null, 3]
//
//解释
//MyLinkedList myLinkedList = new MyLinkedList();
//myLinkedList.addAtHead(1);
//myLinkedList.addAtTail(3);
//myLinkedList.addAtIndex(1, 2);    // 链表变为 1->2->3
//myLinkedList.get(1);              // 返回 2
//myLinkedList.deleteAtIndex(1);    // 现在，链表变为 1->3
//myLinkedList.get(1);              // 返回 3
//
//
//
//
// 提示：
//
//
// 0 <= index, val <= 1000
// 请不要使用内置的 LinkedList 库。
// 调用 get、addAtHead、addAtTail、addAtIndex 和 deleteAtIndex 的次数不超过 2000 。
//
//
// Related Topics 设计 链表 👍 969 👎 0


#include "headers.h"

//leetcode submit region begin(Prohibit modification and deletion)
struct Node {
    int val = 0;
    Node *next = nullptr;
    Node() = default;
    Node(int v) : val(v) {}
};

class MyLinkedList {
private:
    Node *head = nullptr;
    Node *tail = nullptr;
    int size = 0;

public:
    MyLinkedList() {
    }

    int get(int index) {
        if (index < 0 || size <= index) {
            return -1;
        }
        auto cur = head;
        while (index-- > 0) {
            cur = cur->next;
        }
        return cur->val;
    }

    void addAtHead(int val) {
        auto *node = new Node(val);
        node->next = head;
        head = node;
        size++;
        if (tail == nullptr)
            tail = head;
    }

    void addAtTail(int val) {
        auto *node = new Node(val);
        if (tail == nullptr) {
            head = node;
        } else {
            tail->next = node;
        }
        tail = node;
        size++;
    }

    void addAtIndex(int index, int val) {
        // 1. 索引是否有效
        if (index < 0 || index > size)
            return;

        // 2. 索引插入头节点、中间节点、尾节点
        if (index == 0) {
            addAtHead(val);
        } else if (index == size) {
            addAtTail(val);
        } else {
            auto *node = new Node(val);
            auto *cur = head;
            while (--index > 0) {
                cur = cur->next;
            }
            node->next = cur->next;
            cur->next = node;
            size++;
        }
    }

    void deleteAtIndex(int index) {
        // 1. 索引是否有效
        if (index < 0 || index >= size)
            return;
        auto *cur = head;
        Node *tmp;
        // 2. 删除头节点
        if (index == 0) {
            tmp = head;
            head = head->next;
        } else {// 3. 删除其他节点
            // 2. 找到前一个
            while (--index > 0) {
                cur = cur->next;
            }
            tmp = cur->next;
            if (tail == cur->next)
                tail = cur;
            cur->next = cur->next->next;
        }
        delete tmp;
        size--;
        if (size == 0) {
            head = nullptr;
            tail = nullptr;
        }
    }

    void show() {
        cout << "[size: " << size << "] ";
        auto *cur = head;
        while (cur != nullptr) {
            cout << cur->val << " ";
            cur = cur->next;
        }
        cout << " [ " << head->val << " " << tail->val << " ]";
        cout << endl;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    MyLinkedList *obj = new MyLinkedList();
    obj->addAtHead(0);
    cout << obj->get(0) << endl;
    cout << obj->get(1) << endl;

    obj->addAtIndex(1, 4);
    obj->show();

    obj->addAtTail(8);
    obj->addAtHead(5);
    obj->show();
    obj->addAtIndex(4, 3);
    obj->show();

    obj->addAtTail(0);
    obj->addAtTail(5);
    obj->addAtIndex(6, 3);
    obj->show();

    obj->deleteAtIndex(7);
    obj->show();
    obj->deleteAtIndex(5);
    obj->addAtTail(4);
    obj->show();
}