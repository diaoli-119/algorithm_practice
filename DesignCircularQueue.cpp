
class MyCircularQueue {
public:
    MyCircularQueue(int k) {
        size = k;
        head = -1;
        rear = -1;
        queue = new int[k];
    }
    
    bool enQueue(int value) {
        if (isFull()) return false;
        if (head == -1) head = rear = 0;
        else rear = (rear + 1) % size;
        queue[rear] = value;
        return true;
    }
    
    bool deQueue() {
        if (isEmpty()) return false;
        if (head == rear)
        {
            head = rear = -1;
        }
        else 
            head = (head + 1) % size;
        return true;
    }
    
    int Front() {
        return isEmpty() ? -1 : queue[head];
    }
    
    int Rear() {
        return isEmpty() ? -1 : queue[rear];
    }
    
    bool isEmpty() {
        return (head == -1);
    }
    
    bool isFull() {
        if ((rear + 1)%size == head) return true;
        return false;
    }
public:
    int *queue;
    int head;
    int rear;
    int size;
};