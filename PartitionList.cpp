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
    ListNode *partition(ListNode *head, int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ListNode* head1 = NULL;
        ListNode* tail1 = NULL;
        ListNode* head2 = NULL;
        ListNode* tail2 = NULL;
        while(head != NULL) {
            if(head->val < x) {
                if(head1 == NULL) {
                    head1 = head;
                    tail1 = head;
                } else {
                    tail1->next = head;
                    tail1 = tail1->next;
                }
            } else {
                if(head2 == NULL) {
                    head2 = head;
                    tail2 = head;
                } else {
                    tail2->next = head;
                    tail2 = tail2->next;
                }
            }
            head = head->next;
        }
		// set tail2->next to NULL, avoid circular list 
        if(tail2)
            tail2->next = NULL;
        if(tail1 == NULL) {
            return head2;
        } else {
            tail1->next = head2;
            return head1;
        }
    }
};