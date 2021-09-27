/* Program: Circular Queue
 * Weblink: 
 * Author : Karthick Kumaran
 * E-mail : asvkarthick@gmail.com
 */

class MyCircularQueue {
public:
    MyCircularQueue(int k) : data(k + 1) {
        front = 0;
        back = 0;
    }

    bool enQueue(int value) {
        if (isFull()) return false;
        data[front] = value;
        front = (front + 1) % data.size();
        return true;
    }

    bool deQueue() {
        if (isEmpty()) return false;
        back = (back + 1) % data.size();
        return true;
    }

    int Front() {
        if (isEmpty()) return -1;
        return data[back];
    }

    int Rear() {
        if (isEmpty()) return -1;
        if (front == 0)
            return data[data.size() - 1];
        else
            return data[front - 1];
    }

    /* Special conditions for empty and full */
    bool isEmpty() {
        return front == back;
    }

    bool isFull() {
        return back == (front + 1) % data.size();
    }
    std::vector<int> data;
    int front, back;
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
