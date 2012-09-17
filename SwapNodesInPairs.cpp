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
    ListNode *swapPairs(ListNode *head) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ListNode* ln = head;
        while(ln != NULL && ln->next != NULL) {
            int tmp = ln->val;
            ln->val = ln->next->val;
            ln->next->val = tmp;
            ln = ln->next->next;
        }
        return head;
    }
};