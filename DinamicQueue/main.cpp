#include <iostream>
using namespace std;

template <typename T>
struct Node
{
    T value;
    Node<T> *next;

    Node(T value)
    {
        this->value = value;
        next = nullptr;
    }
};

template <typename T>
class DinamicQueue
{
private:
    Node<T> *start;
    Node<T> *end;

public:
    DinamicQueue()
    {
        start = nullptr;
        end = nullptr;
    }

    void enqueue(T value)
    {
        Node<T> *newNode = new Node(value);
        if (isEmpty())
        {
            start = newNode;
        }
        else
        {
            end->next = newNode;
        }

        end = newNode;
    }

    T dequeue()
    {
        if (isEmpty())
        {
            throw runtime_error("Queue Empty!");
        }

        Node<T> *removedNode = start;
        T removedValue = start->value;

        start = start->next;

        if (start == nullptr)
        {
            end = nullptr;
        }

        delete removedNode;
        return removedValue;
    }

    bool isEmpty()
    {
        return start == nullptr && end == nullptr;
    }

    void print()
    {
        if (isEmpty())
        {
            cout << "[]" << endl;
            return;
        }

        cout << "[";
        Node<T> *actual = start;
        while (actual->next != nullptr)
        {
            cout << actual->value << ",";
            actual = actual->next;
        }

        cout << actual->value << "]" << endl;
    }

    ~DinamicQueue()
    {
        while (!isEmpty())
        {
            dequeue();
        }
    }
};

int main()
{
    DinamicQueue<int> *dinamicQueue = new DinamicQueue<int>();

    dinamicQueue->enqueue(1);
    dinamicQueue->enqueue(2);
    dinamicQueue->enqueue(3);

    dinamicQueue->dequeue();
    dinamicQueue->dequeue();
    dinamicQueue->dequeue();

    dinamicQueue->print();

    delete dinamicQueue;

    return 0;
}