#include <iostream>
using namespace std;
template <typename T>
struct Node
{
    T value;
    Node<T> *prev;
    Node<T> *next;

    Node(T value)
    {
        this->value = value;
        next = nullptr;
        prev = nullptr;
    }
};

template <typename T>
class DoubleLinkedList
{
private:
    Node<T> *head;
    Node<T> *tail;

public:
    DoubleLinkedList()
    {
        head = nullptr;
        tail = nullptr;
    }

    void appendLeft(T value)
    {
        Node<T> *newNode = new Node<T>(value);
        if (isEmpty())
        {
            head = newNode;
            tail = newNode;
            return;
        }

        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }

    void appendRight(T value)
    {
        Node<T> *newNode = new Node<T>(value);
        if (isEmpty())
        {
            head = newNode;
            tail = newNode;
            return;
        }

        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }

    T removeLeft()
    {
        if (isEmpty())
        {
            throw runtime_error("List Empty!");
        }

        if (head->next == nullptr)
        {
            T removedValue = head->value;
            delete head;
            head = nullptr;
            tail = nullptr;

            return removedValue;
        }

        Node<T> *removedNode = head;
        T removedValue = head->value;

        head = head->next;
        head->prev = nullptr;
        delete removedNode;

        return removedValue;
    }

    T removeRight()
    {
        if (isEmpty())
        {
            throw runtime_error("List Empty!");
        }

        if (tail->prev == nullptr)
        {
            T removedValue = tail->value;
            delete tail;
            tail = nullptr;
            head = nullptr;

            return removedValue;
        }

        Node<T> *removedNode = tail;
        T removedValue = tail->value;

        tail = tail->prev;
        tail->next = nullptr;
        delete removedNode;

        return removedValue;
    }

    bool isEmpty()
    {
        return head == nullptr && tail == nullptr;
    }

    void print()
    {
        if (isEmpty())
        {
            cout << "[]" << endl;
            return;
        }

        cout << "[";
        Node<T> *actual = head;
        while (actual->next != nullptr)
        {
            cout << actual->value << ",";
            actual = actual->next;
        }

        cout << actual->value << "]" << endl;
    }

    void printReverse()
    {
        if (isEmpty())
        {
            cout << "[]" << endl;
            return;
        }

        cout << "[";
        Node<T> *actual = tail;
        while (actual->prev != nullptr)
        {
            cout << actual->value << ",";
            actual = actual->prev;
        }

        cout << actual->value << "]" << endl;
    }

    ~DoubleLinkedList()
    {
        while (!isEmpty())
        {
            removeRight();
        }
    }
};

int main()
{
    DoubleLinkedList<string> doubleLinkedList = DoubleLinkedList<string>();
    doubleLinkedList.appendRight("1");
    doubleLinkedList.appendRight("2");
    doubleLinkedList.appendRight("3");
    doubleLinkedList.appendRight("4");
    doubleLinkedList.appendRight("5");
    doubleLinkedList.appendLeft("6");

    doubleLinkedList.print();
    doubleLinkedList.printReverse();
}