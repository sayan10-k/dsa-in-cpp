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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode * temp=head;
        for(int i=1; i<k;  i++){
            temp=temp->next;
            
        }
        ListNode * a =temp;

        ListNode * b =head;
        while(temp!=NULL && temp->next!=NULL) {
            temp=temp->next;
            b=b->next;
        }
        swap(a->val,b->val);

        return head;

        
    }
};