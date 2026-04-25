#include <iostream>
using namespace std;

struct Node
{
    int value;
    Node *prev;
    Node *next;

    Node(int value)
    {
        this->value = value;
        next = nullptr;
        prev = nullptr;
    }
};

class DoubleLinkedList
{
private:
    Node *head;
    Node *tail;

public:
    DoubleLinkedList()
    {
        head = nullptr;
        tail = nullptr;
    }

    void appendLeft(int value)
    {
        Node *newNode = new Node(value);
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

    void appendRight(int value)
    {
        Node *newNode = new Node(value);
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

    int removeLeft()
    {
        if (isEmpty())
        {
            throw runtime_error("List Empty!");
        }

        if (head->next == nullptr)
        {
            int removedValue = head->value;
            delete head;
            head = nullptr;
            tail = nullptr;

            return removedValue;
        }

        Node *removedNode = head;
        int removedValue = head->value;

        head = head->next;
        head->prev = nullptr;
        delete removedNode;

        return removedValue;
    }

    int removeRight()
    {
        if (isEmpty())
        {
            throw runtime_error("List Empty!");
        }

        if (tail->prev == nullptr)
        {
            int removedValue = tail->value;
            delete tail;
            tail = nullptr;
            head = nullptr;

            return removedValue;
        }

        Node *removedNode = tail;
        int removedValue = tail->value;

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

        string str = "[";
        Node *actual = head;
        while (actual->next != nullptr)
        {
            str += to_string(actual->value) + ",";
            actual = actual->next;
        }

        str += to_string(actual->value) + "]";
        cout << str << endl;
    }

    void printReverse()
    {
        if (isEmpty())
        {
            cout << "[]" << endl;
            return;
        }

        string str = "[";
        Node *actual = tail;
        while (actual->prev != nullptr)
        {
            str += to_string(actual->value) + ",";
            actual = actual->prev;
        }

        str += to_string(actual->value) + "]";
        cout << str << endl;
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
    DoubleLinkedList doubleLinkedList = DoubleLinkedList();
    doubleLinkedList.appendRight(1);
    doubleLinkedList.appendRight(2);
    doubleLinkedList.appendRight(3);
    doubleLinkedList.appendRight(4);
    doubleLinkedList.appendRight(5);
    doubleLinkedList.appendLeft(6);

    doubleLinkedList.print();
    doubleLinkedList.printReverse();
}