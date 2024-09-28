class MyCircularDeque {
public:
    deque<int> dq;
    int f;
    int temp=0;

    MyCircularDeque(int k) {
        f = k;
    }
    
    bool insertFront(int value) {
        if(!isFull()) {
            dq.push_front(value);
            temp++;
            return true;
        }
        return false;
    }
    
    bool insertLast(int value) {
        if(!isFull()) {
            dq.push_back(value);
            temp++;
            return true;
        }
        return false;
    }
    
    bool deleteFront() {
        if(!isEmpty()) {
            dq.pop_front();
            temp--;
            return true;
        }
        return false;
    }
    
    bool deleteLast() {
        if(!isEmpty()) {
            dq.pop_back();
            temp--;
            return true;
        }
        return false;
    }
    
    int getFront() {
        if(isEmpty()) {
            return -1;  // Return -1 if the deque is empty
        }
        return dq.front();
    }
    
    int getRear() {
        if(isEmpty()) {
            return -1;  // Return -1 if the deque is empty
        }
        return dq.back();
    }
    
    bool isEmpty() {
        return temp == 0;
    }
    
    bool isFull() {
        return temp == f;
    }
};
