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
    ListNode* mergeTwoLists(ListNode* lst1, ListNode* lst2) {
        ListNode* result = NULL; 

	// Base Cases
	if (lst1 == NULL) 
		return (lst2); 
	else if (lst2 == NULL) 
		return (lst1); 

	// recursively merging two lists
	if (lst1->val <= lst2->val) { 
		result = lst1; 
		result->next = mergeTwoLists(lst1->next, lst2); 
	} 
	else { 
		result = lst2; 
		result->next = mergeTwoLists(lst1, lst2->next); 
	} 
	return result; 
    }
};