#include <iostream>
using namespace std;

class StaticStack
{
private:
    int capacity;
    int top = -1;
    int size = 0;
    int *v;

public:
    StaticStack(int capacity)
    {
        this->capacity = capacity;
        v = new int[capacity];
    };

    void push(int value)
    {
        if (isFull())
        {
            throw runtime_error("Stack Overflow!");
        }

        v[++top] = value;
        size++;
    }

    int pop()
    {
        if (isEmpty())
        {
            throw runtime_error("Stack Underflow");
        }

        int removedValue = v[top];
        top--;
        size--;

        return removedValue;
    }

    int peek()
    {
        return v[top];
    }

    int getSize()
    {
        return size;
    }

    int *asArray()
    {
        return v;
    }

    int getTop()
    {
        return top;
    }

    void invert()
    {
        StaticStack *staticStack = new StaticStack(capacity);
        while (!isEmpty())
        {
            staticStack->push(pop());
        }

        top = staticStack->getTop();
        v = staticStack->asArray();
        delete staticStack;
    }

    bool isEmpty()
    {
        return top == -1;
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
        for (int i = top; i > 0; i--)
        {
            cout << v[i] << ",";
        }

        cout << v[0] << "]" << endl;
    }
};

int main()
{
    StaticStack staticStack = StaticStack(10);
    staticStack.push(1);
    staticStack.push(2);
    staticStack.push(3);
    staticStack.pop();
    staticStack.push(4);

    staticStack.print();
    staticStack.invert();
    staticStack.print();
}