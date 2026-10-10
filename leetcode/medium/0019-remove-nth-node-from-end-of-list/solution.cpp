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
 int size(ListNode* head){
    
    ListNode*temp=head;
    int count=0;
    while(temp!=nullptr){
        count++;
        temp=temp->next;


    }
    return count;

 }

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int length= size(head);
        ListNode* prev=head;
        ListNode* temp;

        if(length==n) {
            return head->next;
        }
    
        for(int i=1; i<length - n ; i++) {
            prev=prev->next;

        }
        
        temp=prev->next;
        prev->next=prev->next->next;
        
        temp->next=NULL;
        delete temp;
        return head;

    }
};