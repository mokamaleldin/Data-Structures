#include <iostream>
#define nullptr NULL
using namespace std;

class TreeNode
{
public:
    int data;
    TreeNode *left;
    TreeNode *right;

    // Constructor
    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

class BST
{
public:
    TreeNode *root;

    // Constructor
    BST() : root(nullptr) {}

    // Insert function
    TreeNode *insert(TreeNode *node, int val)
    {
        if (node == nullptr)
        {
            return new TreeNode(val);
        }

        if (val < node->data)
        {
            node->left = insert(node->left, val);
        }
        else if (val > node->data)
        {
            node->right = insert(node->right, val);
        }

        return node;
    }

    // Delete function
    TreeNode *deleteNode(TreeNode *node, int val)
    {
        if (node == nullptr)
        {
            return node;
        }

        if (val < node->data)
        {
            node->left = deleteNode(node->left, val);
        }
        else if (val > node->data)
        {
            node->right = deleteNode(node->right, val);
        }
        else
        {
            if (node->left == nullptr)
            {
                TreeNode *temp = node->right;
                delete node;
                return temp;
            }
            else if (node->right == nullptr)
            {
                TreeNode *temp = node->left;
                delete node;
                return temp;
            }

            TreeNode *temp = minValueNode(node->right);
            node->data = temp->data;
            node->right = deleteNode(node->right, temp->data);
        }

        return node;
    }

    // Helper function to find the minimum value node
    TreeNode *minValueNode(TreeNode *node)
    {
        TreeNode *current = node;
        while (current && current->left != nullptr)
        {
            current = current->left;
        }
        return current;
    }

    // Inorder traversal
    void inorderTraversal(TreeNode *node)
    {
        if (node == nullptr)
            return;

        inorderTraversal(node->left);
        cout << node->data << " ";
        inorderTraversal(node->right);
    }

    // Search function
    bool search(TreeNode *node, int val)
    {
        if (node == nullptr)
        {
            return false;
        }

        if (val == node->data)
        {
            return true;
        }
        else if (val < node->data)
        {
            return search(node->left, val);
        }
        else
        {
            return search(node->right, val);
        }
    }
};

int main()
{
    BST tree;

    // Insert nodes
    tree.root = tree.insert(tree.root, 50);
    tree.insert(tree.root, 30);
    tree.insert(tree.root, 70);
    tree.insert(tree.root, 20);
    tree.insert(tree.root, 40);
    tree.insert(tree.root, 60);
    tree.insert(tree.root, 80);

    cout << "Inorder Traversal before deletion: ";
    tree.inorderTraversal(tree.root);
    cout << endl;

    // Delete a node
    tree.root = tree.deleteNode(tree.root, 50);

    cout << "Inorder Traversal after deletion: ";
    tree.inorderTraversal(tree.root);
    cout << endl;

    // Search for a value
    int value = 40;
    if (tree.search(tree.root, value))
    {
        cout << "Value " << value << " found in the BST." << endl;
    }
    else
    {
        cout << "Value " << value << " not found in the BST." << endl;
    }

    return 0;
}
