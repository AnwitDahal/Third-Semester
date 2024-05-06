#include <iostream>
#include <cstddef>
using namespace std;

// Define the structure of a node in the BST
struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

// Function to insert a new node into the BST
void insert(TreeNode*& root, int val) {
    if (root == nullptr) {
        root = new TreeNode(val);
        return;
    }
    if (val < root->data) {
        insert(root->left, val);
    } else {
        insert(root->right, val);
    }
}

// Function to search for a value in the BST
bool search(TreeNode* root, int val) {
    if (root == nullptr) return false;
    if (root->data == val) return true;
    if (val < root->data) {
        return search(root->left, val);
    } else {
        return search(root->right, val);
    }
}

// Function to find the minimum value node in a subtree
TreeNode* findMin(TreeNode* root) {
    while (root->left != nullptr) {
        root = root->left;
    }
    return root;
}

// Function to delete a node from the BST
TreeNode* remove(TreeNode*& root, int val) {
    if (root == nullptr) return root;
    if (val < root->data) {
        root->left = remove(root->left, val);
    } else if (val > root->data) {
        root->right = remove(root->right, val);
    } else {
        if (root->left == nullptr) {
            TreeNode* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == nullptr) {
            TreeNode* temp = root->left;
            delete root;
            return temp;
        }
        TreeNode* temp = findMin(root->right);
        root->data = temp->data;
        root->right = remove(root->right, temp->data);
    }
    return root;
}

// Function to perform in-order traversal of the BST
void inorderTraversal(TreeNode* root) {
    if (root == nullptr) return;
    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}

// Function to perform pre-order traversal of the BST
void preorderTraversal(TreeNode* root) {
    if (root == nullptr) return;
    cout << root->data << " ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

// Function to perform post-order traversal of the BST
void postorderTraversal(TreeNode* root) {
    if (root == nullptr) return;
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    cout << root->data << " ";
}

int main() {
    TreeNode* root = nullptr;
    // Insertion
    insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    // Search
    cout << "Is 20 present in the tree? " << (search(root, 20) ? "Yes" : "No") << endl;
    cout << "Is 90 present in the tree? " << (search(root, 90) ? "Yes" : "No") << endl;

    // Deletion
    remove(root, 20);

    // Traversal
    cout << "In-order traversal: ";
    inorderTraversal(root);
    cout << endl;

    cout << "Pre-order traversal: ";
    preorderTraversal(root);
    cout << endl;

    cout << "Post-order traversal: ";
    postorderTraversal(root);
    cout << endl;

    return 0;
}

