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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int count=0;
    ListNode *p=head;
    if(head==NULL) return NULL;
    while(p!=NULL)
    {
        p=p->next;
        count++;
    }
    
    if(count<n) return NULL;
    
    int diff=count-n;
    if(diff==0) return head->next;
    p=head;
    while(diff!=1)
    {
        p=p->next;
        diff--;
    }
    p->next=p->next->next;
    
    return head;
    }
};