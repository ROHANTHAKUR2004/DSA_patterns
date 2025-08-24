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
    ListNode* oddEvenList(ListNode* head) {
        
        ListNode* dummy = new ListNode(-1);
        ListNode* ptr = dummy;

        queue<ListNode*> q;

        int idx = 1;

        while(head){
            if(idx % 2 !=0){
                ptr->next = head;
                ptr = ptr->next;
            }
            else {
                 q.push(head);
            }
            head = head->next;
            idx++;
        }
        while(!q.empty()){

            ptr->next = q.front();
            q.pop();

            ptr = ptr->next;
        }
        ptr->next= NULL;
        return dummy->next;
    }
};