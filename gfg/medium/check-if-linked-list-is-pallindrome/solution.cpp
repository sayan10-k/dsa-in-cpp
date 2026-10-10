/*
class Node {
  public:
    int data;
    Node *next;

    Node(int x) {
       data = x;
       next = nullptr;
    }
};*/

class Solution {
  public:
    bool isPalindrome(Node *head) {
        //  code here
        stack<int>st;
        
        Node *temp=head;
        while(temp!=NULL){
            st.push(temp->data);
            temp=temp->next;
            
        }
        
        Node * ndhead=head;
        
        while(!st.empty()  &&  ndhead!=NULL){
            
            if(st.top() !=  ndhead->data) {
                return false;
                
            }
            st.pop();
            ndhead=ndhead->next;
            
        }
        
        return true;
        
    }
};