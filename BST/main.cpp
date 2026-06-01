#include <iostream>
using namespace std;

struct Node
{
    int value;
    Node *right;
    Node *left;

    Node(int value)
    {
        this->value = value;
        right = nullptr;
        left = nullptr;
    }
};

class BinarySearchTree
{
private:
    Node *root;
    Node *putRecursively(Node *actual, int value)
    {
        if (actual == nullptr)
        {
            return new Node(value);
        }

        if (value > actual->value)
        {
            actual->right = putRecursively(actual->right, value);
        }
        else if (value < actual->value)
        {
            actual->left = putRecursively(actual->left, value);
        }

        return actual;
    }

    bool containsRecursively(Node *actual, int value)
    {
        if (actual == nullptr)
        {
            return false;
        }

        if (actual->value == value)
        {
            return true;
        }

        if (value > actual->value)
        {
            return containsRecursively(actual->right, value);
        }

        return containsRecursively(actual->left, value);
    }

public:
    BinarySearchTree()
    {
        this->root = nullptr;
    }

    int put(int value)
    {
        root = putRecursively(root, value);
        return value;
    }

    bool contains(int value)
    {
        return containsRecursively(root, value);
    }
};

int main()
{
    BinarySearchTree bst = BinarySearchTree();
    bst.put(1);
    bst.put(3);
    bst.put(4);
    bst.put(6);
    bst.put(8);
    bst.put(12);
    bst.put(156);
    bst.put(20);
    cout << bst.contains(20) << endl;

    return 0;
}