#include <iostream>
using namespace std;

template <typename T>
struct Node
{
    T value;
    Node<T> *prev;

    Node(T value)
    {
        this->value = value;
        prev = nullptr;
    }
};

template <typename T>
class Stack
{
private:
    Node<T> *top;

public:
    Stack()
    {
        top = nullptr;
    }

    void push(T value)
    {
        Node<T> *newNode = new Node<T>(value);
        newNode->prev = top;
        top = newNode;
    }

    T pop()
    {
        if (isEmpty())
        {
            throw runtime_error("Stack Underflow!");
        }

        Node<T> *removedNode = top;
        T removedValue = removedNode->value;
        top = top->prev;
        delete removedNode;

        return removedValue;
    }

    T peek()
    {
        if (isEmpty())
        {
            throw runtime_error("Stack Underflow!");
        }

        return top->value;
    }

    void reverse()
    {
        Node<T> *prev = nullptr;
        Node<T> *current = top;

        while (current != nullptr)
        {
            Node<T> *next = current->prev;
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

        cout << "[";
        Node<T> *actual = top;
        while (actual->prev != nullptr)
        {
            cout << actual->value << ",";
            actual = actual->prev;
        }

        cout << actual->value << "]" << endl;
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
    Stack<int> stack = Stack<int>();
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