#include <iostream>

using namespace std;

// Node structure for threaded binary tree
struct Node
{
    int data;
    Node *left;
    Node *right;
    bool isThreadedRight;

    Node(int val) : data(val), left(nullptr), right(nullptr), isThreadedRight(false) {}
};

// Function to insert a node in the threaded binary tree
Node *insert(Node *root, int val)
{
    Node *newNode = new Node(val);
    if (root == nullptr)
    {
        root = newNode;
        return root;
    }

    Node *current = root;
    while (true)
    {
        if (val < current->data)
        {
            if (current->left == nullptr)
            {
                current->left = newNode;
                newNode->right = current;
                newNode->isThreadedRight = true;
                return root;
            }
            else
            {
                current = current->left;
            }
        }
        else
        {
            if (current->isThreadedRight)
            {
                newNode->right = current->right;
                current->right = newNode;
                current->isThreadedRight = false;
                newNode->isThreadedRight = true;
                return root;
            }
            else if (current->right == nullptr)
            {
                current->right = newNode;
                return root;
            }
            else
            {
                current = current->right;
            }
        }
    }
}

// Function to perform in-order traversal of the threaded binary tree
void inOrderTraversal(Node *root)
{
    if (root == nullptr)
    {
        cout << "Tree is empty" << endl;
        return;
    }

    Node *current = root;
    while (current != nullptr)
    {
        while (current->left != nullptr)
            current = current->left;

        cout << current->data << " ";

        if (current->isThreadedRight)
            current = current->right;
        else
            current = current->right;
    }
    cout << endl;
}

int main()
{
    Node *root = nullptr;

    // Inserting elements into the threaded binary tree
    root = insert(root, 5);
    root = insert(root, 3);
    root = insert(root, 7);
    root = insert(root, 2);
    root = insert(root, 4);
    root = insert(root, 6);
    root = insert(root, 8);

    // In-order traversal
    cout << "In-order traversal: ";
    inOrderTraversal(root);

    return 0;
}