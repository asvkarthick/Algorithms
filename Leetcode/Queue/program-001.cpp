/* Program to implement circular buffer
 * Author : Karthick Kumaran
 * E-mail : asvkarthick@gmail.com
 */

#include <iostream>

class CircularBuffer
{
public:
    explicit CircularBuffer(int n) : mNumElements{n}
    {
        mHead = 0;
        mTail = 0;
        mArr = new int[n];
        std::cout << "Circular buffer constructed with " << n << " elements" << std::endl;
    }

    ~CircularBuffer()
    {
        delete mArr;
        std::cout << "Circular buffer destroyed" << std::endl;
    }

    bool enqueue(int data)
    {
        if (mHead == ((mTail + 1) % mNumElements)) {
            std::cerr << "Queue is full" << std::endl;
            return false;
        }
        mArr[mTail] = data;
        std::cout << "Enqueued " << data << " at pos " << mTail << std::endl;
        mTail = (mTail + 1) % mNumElements;
        return true;
    }

    int dequeue()
    {
        if (mHead == mTail) {
            std::cerr << "Queue is empty" << std::endl;
            return -1;
        }
        int data = mArr[mHead];
        mHead = (mHead + 1) % mNumElements;
        return data;
    }

private:
    int mNumElements;
    int mHead;
    int mTail;
    int *mArr;
};

int main(void)
{
    CircularBuffer c(10);
    for (int i = 0; i < 100; i++) c.enqueue(i);
    for (int i = 0; i < 100; i++) std::cout << c.dequeue() << std::endl;

    return 0;
}
