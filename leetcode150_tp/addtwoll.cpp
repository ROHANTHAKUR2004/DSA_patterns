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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(-1);
        ListNode* ptr = dummy;

        int carry = 0;

        while(l1 || l2 || carry){

            int n = 0;
            if(l1) n = l1->val;

            int n2 = 0;
            if(l2) n2 = l2->val;

            int sum = n + n2 + carry;

            ListNode* temp = new ListNode(sum %10);

            carry = sum/10;

            ptr->next = temp;
            ptr = ptr->next;

            if(l1) l1 = l1->next;
            if(l2) l2 = l2->next;
        }
        
        return dummy->next;
    }
};