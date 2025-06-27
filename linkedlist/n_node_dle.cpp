#include <cstddef>

 
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

  
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp = head;
        
        int length = 0;
        while(temp){
            length++;
            temp = temp->next;
        }
       
        
        
        if (length == n) {
            return head->next;
        } 
        
        
        int del = length - n  ;
        
        temp = head;
        int c =0;
        ListNode* prev = NULL;
        
        while(temp){
            
            if(c == del){
                prev->next = temp->next;  
            
            }
            
            prev = temp;
            
            c++;
            temp = temp->next;
            
        }
        return head;    
    }
};