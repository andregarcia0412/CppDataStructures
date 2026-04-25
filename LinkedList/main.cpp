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
class LinkedList
{
private:
    Node<T> *head;

public:
    LinkedList()
    {
        head = nullptr;
    }

    void appendLeft(T value)
    {
        Node<T> *newNode = new Node<T>(value);
        if (isEmpty())
        {
            head = newNode;
            return;
        }

        newNode->next = head;
        head = newNode;
    }

    void appendRight(T value)
    {
        Node<T> *newNode = new Node<T>(value);
        if (isEmpty())
        {
            head = newNode;
            return;
        }

        Node<T> *actual = head;

        while (actual->next != nullptr)
        {
            actual = actual->next;
        }

        actual->next = newNode;
    }

    T removeLeft()
    {
        if (isEmpty())
        {
            throw runtime_error("List Empty!");
        }

        T removedValue = head->value;
        Node<T> *removedNode = head;
        head = head->next;

        delete removedNode;
        return removedValue;
    }

    T removeRight()
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
            return removedValue;
        }

        Node<T> *actual = head;
        while (actual->next->next != nullptr)
        {
            actual = actual->next;
        }

        T removedValue = actual->next->value;
        delete actual->next;
        actual->next = nullptr;

        return removedValue;
    }

    void reverse()
    {
        Node<T> *prev = nullptr;
        Node<T> *current = head;

        while (current != nullptr)
        {
            Node<T> *next = current->next;
            current->next = prev;

            prev = current;
            current = next;
        }

        head = prev;
    }

    bool isEmpty()
    {
        return head == nullptr;
    }

    void print()
    {
        if (isEmpty())
        {
            cout << "[]" << endl;
            return;
        }

        Node<T> *actual = head;
        cout << "[";
        while (actual->next != nullptr)
        {
            cout << actual->value << ",";
            actual = actual->next;
        }

        cout << actual->value << "]" << endl;
    }

    ~LinkedList()
    {
        while (!isEmpty())
        {
            removeLeft();
        }
    }
};

int main()
{
    LinkedList<int> linkedList = LinkedList<int>();
    linkedList.appendRight(1);
    linkedList.appendRight(2);
    linkedList.appendRight(3);
    linkedList.appendRight(4);
    linkedList.appendRight(5);

    linkedList.removeLeft();
    linkedList.removeRight();

    linkedList.print();

    linkedList.appendLeft(6);

    linkedList.reverse();

    linkedList.print();

    return 0;
}