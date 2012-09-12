/*******************************
You are given two linked lists
representing two non-negative 
numbers. The digits are stored 
in reverse order and each of 
their nodes contain a single 
digit. Add the two numbers and 
return it as a linked list.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
*******************************/
// struct ListNode
// {
//   int val;
//   ListNode *next;
//   ListNode (int v = 0) : val(v), next(NULL){};
// };
class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
      if (l1 == NULL && l2 == NULL)
	return NULL;
      ListNode *result = NULL;
      ListNode *head = result;
      int carry = 0;
      while (!(l1 == NULL && l2 == NULL))
      {
	int m = 0;
	ListNode *temp = new ListNode(0);
	if (head != NULL)
	  head -> next = temp;
	if (l1 != NULL)
	{
	  m += l1 -> val;
	  l1 = l1 -> next;
	  if (result == NULL)
	    result = temp;
	}
	if (l2 != NULL)
	{
	  m += l2 -> val;
	  l2 = l2 -> next;
	  if (result == NULL)
	    result = temp;
	}
	m += carry;
	carry = m / 10;
	temp -> val = m % 10;
	head = temp;
      }
      if (carry != 0)
      {
	ListNode *temp = new ListNode(0);
	temp -> val = carry;
	head -> next = temp;
      }
      return result;
    }
};
