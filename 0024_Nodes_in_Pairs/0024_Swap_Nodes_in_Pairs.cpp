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
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL or head -> next==NULL){
            return head ;
        }
        else{
            //Reverse first pair
            ListNode *temp=head->next;
            head->next = temp->next;
            temp ->next = head;
            head = temp;
            //Call the method recursive for next
            head->next->next = swapPairs(head->next->next);
            return head;
        }
    }
};