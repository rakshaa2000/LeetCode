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
     
    tuple<ListNode*, ListNode*> reverse(ListNode* head, int k) {
        
        auto last = head;
        auto cur = head;
        auto next = cur->next;
        for(int i = 0; i < k; i++) {
            
            // relink these
            auto a = cur;
            auto b = next;
            
            // go to the next one
            cur = next;
            next = cur->next;
            
            b->next = a;
        }
        
        // relink the list
        last->next = next;
        
        return {cur, last};
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        // figure out how many nodes there are
        ListNode* cur = head;
        int n = 0;
        while(cur != nullptr){
            cur = cur->next;
            n++;
        }
        
        // do we even need to swap
        if(n < k) {
            return head; 
        }
        
        // now we know how many times to do this
        cur = head;
        ListNode* prev = nullptr;
        for(int i = 0; i < (n / k); ++i) {

            auto x = reverse(cur, k - 1);

            if(i == 0) {
                head = std::get<0>(x);
            }
            
            cur = std::get<1>(x)->next;
            if(prev != nullptr) {
                prev->next = std::get<0>(x);
            }
            
            prev = std::get<1>(x);
        }
        
        return head;
    }
};