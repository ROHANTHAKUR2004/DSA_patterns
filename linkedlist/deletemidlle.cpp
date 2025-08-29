class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if (!head || !head->next) return nullptr; 
        
        ListNode* temp = head;
        int len = 0;
        while (temp) {
            len++;
            temp = temp->next;
        }

       
        int dnode = len / 2;

        temp = head;
        ListNode* prev = nullptr;
        for (int i = 0; i < dnode; i++) {
            prev = temp;
            temp = temp->next;
        }
        prev->next = temp->next;
        delete temp;

        return head;
    }
};
