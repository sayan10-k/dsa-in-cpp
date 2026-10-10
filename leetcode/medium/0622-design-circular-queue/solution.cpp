class MyCircularQueue {
public:
    int *arr;
    int capacity;
    int currsize;
    int f,r;
    MyCircularQueue(int k) {
        this->capacity=k;
        arr=new int[capacity];
        currsize=0;
        f=0;
        r=-1;
        
    }
    
    bool enQueue(int value) {
        if(currsize==capacity) {
            return false;
        }
        r=(r+1)%capacity;
        arr[r]=value;
        currsize++;
        return true;
        
    }
    
    bool deQueue() {
        if(isEmpty()) return false;
        f=(f+1)%capacity;
        currsize--;
        return true;

        
    }
    
    int Front() {
        if(isEmpty()) return -1;
        return arr[f];
        
    }
    
    int Rear() {
        if(isEmpty()) return -1;
        return arr[r];


        
    }
    
    bool isEmpty() {
        return currsize==0;
        
    }
    
    bool isFull() {
        return currsize==capacity;
        
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */