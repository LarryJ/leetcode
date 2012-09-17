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
    ListNode *rotateRight(ListNode *head, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(head == NULL)
        	return NULL;
        ListNode* fast = head;
        ListNode* slow = head;
        // move fast k steps forward
        for(int i = 0; i < k; i++) {
        	fast = fast->next;
        	if(fast == NULL)
        		fast = head;
        }
        if(fast == slow)
        	return head;
        // move fast and slow at the same time
        while(fast->next != NULL) {
        	slow = slow->next;
        	fast = fast->next;
        }
        ListNode* newHead = slow->next;
        slow->next = NULL;
        fast->next = head;
        return newHead;
    }
};
