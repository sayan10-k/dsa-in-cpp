/* Structure of Linked List Node
class Node {
  public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};*/

class Solution {
  public:
    void linkDelete(Node* head, int n, int m) {
        if (!head || m <= 0) return;
        
            Node* temp = head;
            
            while (temp != nullptr) {
                // Skip M-1 nodes
                for (int i = 1; i < m && temp != nullptr; i++){
                    temp = temp->next;
                    
                }
                
                if (temp == nullptr) return;
                // Delete N nodes
                
                Node* end = temp->next;
                
                for (int i = 0; i < n && end != nullptr; i++) {
                    Node* toDelete = end;
                    end = end->next;
                    delete toDelete;
                }
                temp->next = end;
                temp = end;
            }
        

        
        
        
        
    }
};