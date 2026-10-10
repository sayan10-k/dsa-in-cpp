class Node {
  public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};

class myQueue {
    Node * head;
    Node * tail;
    

  public:
    myQueue() {
        head=nullptr;
        tail=nullptr;
        
    }

    bool isEmpty() {
        return head==nullptr;
        
        // check if the queue is empty
    }

    void enqueue(int x) {
        Node * newnode=new Node(x);
        if(head==nullptr) {
            head=tail=newnode;
        }
        else{
            tail->next=newnode;
            tail=newnode;
            
        }
        // Adds an element x at the rear of the queue
    }

    void dequeue() {
        Node * temp=head;
        head=head->next;
        temp->next=NULL;
        delete temp;
        // Removes the front element of the queue
    }

    int getFront() {
        if(isEmpty()) {
            return -1;
        }
        return head->data;
        // Returns the front element of the queue
        // If queue is empty, return -1
    }

    int size() {
        int sz=0;
        Node* temp=head;
        while(temp!=NULL){
            sz++;
            temp=temp->next;
        }
        return sz;
        // Returns the current size of the queue.
    }
};
