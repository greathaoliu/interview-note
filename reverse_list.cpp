#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* ReverseList(ListNode* head) {
    if(head == nullptr||head->next == nullptr) return head;
    ListNode* p = ReverseList(head->next);
    head->next->next = head;
    head->next = nullptr;
    return p;
}

// 1->2->3->4->nullptr
ListNode* ReverseListIteration(ListNode* head) {
    ListNode* cur = nullptr, *pre = head;
    while (pre != nullptr) {
        ListNode* t = pre->next;
        pre->next = cur;
        cur = pre;
        pre = t;
    }
    return cur;
}

int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);

    ListNode* p = head;
    while(p != nullptr) {
        cout<<p->val<<" ";
        p = p->next;
    }

    cout<<endl;

    p = ReverseListIteration(head);
    while(p != nullptr) {
        cout<<p->val<<" ";
        p = p->next;
    }
}