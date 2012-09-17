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
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
    	// 1 <= m <= n <= length of list
    	if(head == NULL || head->next == NULL) 
    		return head;
    	ListNode* before = NULL;
    	ListNode* beforeRear = NULL;
    	if(m != 1) {
    		before = head;
    		beforeRear = head;
    	}
    	for(int i = 0; i < m - 1; i++) {
   			beforeRear = beforeRear->next;
    	}
    	ListNode* start = NULL;
    	if(m != 1)
    		start = beforeRear->next; // the head of the between list
    	else
    		start = head;
    	ListNode* end = start; // the rear of the between list
    	for(int i = 0; i < n - m; i++) {
    		end = end->next;
    	}
    	ListNode* after = end->next;
    	// reverse the between list
    	end = start; // end will be the tail of the reversed list
    	ListNode* newStart = reverse(start);
    	if(beforeRear) {
    		beforeRear->next = newStart;
    	}
    	end->next = after;
    	if(before)
    		return before;
    	return newStart;
    }

    ListNode* reverse(ListNode* head) {
    	if(head == NULL || head->next == NULL)
    		return head;
    	ListNode* newHead = reverse(head->next);
    	head->next->next = head;
    	head->next = NULL;
    	return newHead;
    }
};