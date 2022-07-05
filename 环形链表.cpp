/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* p = head;
        bool is_loop = false;
        map<ListNode*, bool> visited;
        while (true) {
            if (p == nullptr) {
                break;
            }
            if (visited[p]) {
                is_loop = true;
                break;
            }
            visited[p] = true;
            p = p -> next;
        }
        return is_loop;
    }
};
