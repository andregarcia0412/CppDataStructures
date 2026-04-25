#include <iostream>
using namespace std;

class Node
{
public:
    int value;
    Node *prev;

    Node(int value)
    {
        this->value = value;
        prev = nullptr;
    }
};

class Stack
{
private:
    Node *top;

public:
    Stack()
    {
        top = nullptr;
    }

    void push(int value)
    {
        Node *newNode = new Node(value);
        newNode->prev = top;
        top = newNode;
    }

    int pop()
    {
        if (isEmpty())
        {
            throw runtime_error("Stack Underflow!");
        }

        Node *removedNode = top;
        int removedValue = removedNode->value;
        top = top->prev;
        delete removedNode;

        return removedValue;
    }

    Node *peek()
    {
        return top;
    }

    void reverse()
    {
        Node *prev = nullptr;
        Node *current = top;

        while (current != nullptr)
        {
            Node *next = current->prev;
            current->prev = prev;

            prev = current;
            current = next;
        }

        top = prev;
    }

    bool isEmpty()
    {
        return top == nullptr;
    }

    void print()
    {
        if (isEmpty())
        {
            cout << "[]" << endl;
            return;
        }

        string str = "[";
        Node *actual = top;
        while (actual->prev != nullptr)
        {
            str += to_string(actual->value) + ",";
            actual = actual->prev;
        }

        str += to_string(actual->value) + "]";
        cout << str << endl;
    }

    ~Stack()
    {
        while (!isEmpty())
        {
            pop();
        }
    }
};

int main()
{
    Stack stack = Stack();
    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.push(4);
    stack.push(5);

    stack.print();

    stack.pop();
    stack.reverse();

    stack.print();
    return 0;
}