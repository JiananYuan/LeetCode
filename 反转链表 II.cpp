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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        // 虚拟头节点
        ListNode* tmp_head = new ListNode;
        tmp_head -> next = head;

        ListNode* begin;
        ListNode* begin_before = tmp_head;
        ListNode* end = tmp_head;
        ListNode* end_next;
        for (int i = 0; i < left - 1; i += 1) {
            begin_before = begin_before -> next;
        }
        begin = begin_before -> next;
        for (int i = 0; i < right; i += 1) {
            end = end -> next;
        }
        end_next = end -> next;
        ListNode* p = begin;
        ListNode* q = begin -> next;
        while (q != end_next) {
            ListNode* tmp = q -> next;
            q -> next = p;
            p = q;
            q = tmp;
        }
        begin_before -> next = end;
        begin -> next = end_next;
        return tmp_head -> next;
    }
};
