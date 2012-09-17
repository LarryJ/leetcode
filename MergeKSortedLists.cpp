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
    struct myComp {
        bool operator() (ListNode* a, ListNode* b) {
            return (a->val > b->val);
        }
    };

    ListNode *mergeKLists(vector<ListNode *> &lists) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ListNode* head = NULL;
        ListNode* tail = NULL;
        priority_queue<ListNode*, vector<ListNode*>, myComp> pq;
        for(int i = 0; i < lists.size(); i++) {
            if(lists[i] != NULL) {
                pq.push(lists[i]);
            }
        }
        while(!pq.empty()) {
            ListNode* ln = pq.top();
            pq.pop();
            if(ln->next)
                pq.push(ln->next);
            if(head == NULL) {
                head = ln;
                tail = ln;
                tail->next = NULL;
            } else {
                tail->next = ln;
                tail = tail->next;
                tail->next = NULL;
            }
        }
        return head;
    }
};