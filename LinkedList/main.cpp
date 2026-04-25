#include <iostream>
using namespace std;

struct Node
{
    int value;
    Node *next;

    Node(int value)
    {
        this->value = value;
        next = nullptr;
    }
};

class LinkedList
{
private:
    Node *head;

public:
    LinkedList()
    {
        head = nullptr;
    }

    void appendLeft(int value)
    {
        Node *newNode = new Node(value);
        if (isEmpty())
        {
            head = newNode;
            return;
        }

        newNode->next = head;
        head = newNode;
    }

    void appendRight(int value)
    {
        Node *newNode = new Node(value);
        if (isEmpty())
        {
            head = newNode;
            return;
        }

        Node *actual = head;

        while (actual->next != nullptr)
        {
            actual = actual->next;
        }

        actual->next = newNode;
    }

    int removeLeft()
    {
        if (isEmpty())
        {
            throw runtime_error("List Empty!");
        }

        int removedValue = head->value;
        Node *removedNode = head;
        head = head->next;

        delete removedNode;
        return removedValue;
    }

    int removeRight()
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
            return removedValue;
        }

        Node *actual = head;
        while (actual->next->next != nullptr)
        {
            actual = actual->next;
        }

        int removedValue = actual->next->value;
        delete actual->next;
        actual->next = nullptr;

        return removedValue;
    }

    void reverse()
    {
        Node *prev = nullptr;
        Node *current = head;

        while (current != nullptr)
        {
            Node *next = current->next;
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

        Node *actual = head;
        string str = "[";
        while (actual->next != nullptr)
        {
            str += to_string(actual->value) + ",";
            actual = actual->next;
        }

        str += to_string(actual->value) + "]";
        cout << str << endl;
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
    LinkedList linkedList = LinkedList();
    linkedList.appendRight(1);
    linkedList.appendRight(2);
    linkedList.appendRight(3);
    linkedList.appendRight(4);
    linkedList.appendRight(5);

    linkedList.removeLeft();
    linkedList.removeRight();

    linkedList.appendLeft(6);

    linkedList.reverse();

    linkedList.print();

    return 0;
}