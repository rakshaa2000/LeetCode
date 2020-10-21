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
int t=0;
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int sum = 0;               // digit sum and carry
        ListNode * res = nullptr;  // result to return
        ListNode ** l3 = &res;     // pointer to current list node pointer 
        while (true) {
            if (!l1 && !l2 && !sum) {
                break;             // no more digits and carry => we're done!
            }
            if (l1) {              // we have digit from addendum1
                sum += l1->val;    // add it to carry
                l1 = l1->next;     // proceed to the next digit of addendum1
            }
            if (l2) {              // we have digit from addendum2
                sum += l2->val;    // add it to carry
                l2 = l2->next;     // proceed to the next digit of addendum2
            }
            *l3 = new ListNode(sum % 10); // create current result digit node
            l3 = &((*l3)->next);          // proceed to the next result digit
            sum /= 10;                    // carry
        }
        return res;
 
    }
};
