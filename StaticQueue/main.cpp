#include <iostream>
using namespace std;

class StaticQueue
{
private:
    int start = 0;
    int end = -1;
    int size = 0;
    int capacity;
    int *v;

public:
    StaticQueue(int capacity)
    {
        this->capacity = capacity;
        v = new int[capacity];
    }

    void enqueue(int value)
    {
        if (isFull())
        {
            throw runtime_error("Queue Full!");
        }

        end = (end + 1) % capacity;
        v[end] = value;
        size++;
    }

    int dequeue()
    {
        if (isEmpty())
        {
            throw runtime_error("Queue Empty!");
        }

        int removedValue = v[start];
        start = (start + 1) % capacity;
        size--;

        return removedValue;
    }

    bool isEmpty()
    {
        return size == 0;
    }

    bool isFull()
    {
        return size == capacity;
    }

    void print()
    {
        if (isEmpty())
        {
            cout << "[]" << endl;
            return;
        }

        cout << "[";
        for (int i = start; i != end; i = (i + 1) % capacity)
        {
            cout << v[i] << ",";
        }

        cout << v[end] << "]" << endl;
    }
};

int main()
{

    StaticQueue staticQueue = StaticQueue(10);
    staticQueue.enqueue(1);
    staticQueue.enqueue(2);
    staticQueue.enqueue(3);

    staticQueue.print();
    staticQueue.dequeue();
    staticQueue.dequeue();
    staticQueue.print();

    staticQueue.enqueue(4);
    staticQueue.enqueue(5);
    staticQueue.enqueue(6);
    staticQueue.enqueue(7);
    staticQueue.enqueue(8);
    staticQueue.dequeue();
    staticQueue.dequeue();
    staticQueue.dequeue();
    staticQueue.enqueue(9);
    staticQueue.enqueue(10);
    staticQueue.enqueue(11);

    staticQueue.print();

    return 0;
}