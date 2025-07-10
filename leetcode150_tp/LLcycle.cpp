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
    bool hasCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast && fast->next){
             slow = slow->next;
             fast = fast->next->next;

             if(fast == slow) return true;
        }
        return false;
    }
};


// 2 approch

    // unordered_set<ListNode*> st;

    //     while(head){
    //         if(st.count(head)) return true;
    //         st.insert(head);
    //         head = head->next;
    //     }
    //     return false;
    