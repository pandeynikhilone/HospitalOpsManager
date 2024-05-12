// Data structure used in "Patient Cabin Managment" is "Binary Search Tree"
// This Header file Contains implementation of "Binary Search Tree"

#ifndef BST_HPP
#define BST_HPP

#include <iostream>
#include <string>

struct TreeNode {
    std::string cabin_code;
    bool isAvl;

    TreeNode(std::string a, bool b) : cabin_code(a), isAvl(b) {}
};

class BinarySearchTree {
private:
    struct Node {
        TreeNode* data;
        Node* left;
        Node* right;

        Node(TreeNode* item) : data(item), left(nullptr), right(nullptr) {}
    };

    Node* root;

    // DATA IS INSERTED INTO BST
    void insertHelper(Node*& node, TreeNode* item) {
        if (node == nullptr) {
            node = new Node(item);
        } else if (item->cabin_code < node->data->cabin_code) {
            insertHelper(node->left, item);
        } else {
            insertHelper(node->right, item);
        }
    }

    TreeNode* searchHelper(Node* node, const std::string& key) {
        if (node == nullptr || node->data->cabin_code == key) {
            return (node == nullptr) ? nullptr : node->data;
        } else if (key < node->data->cabin_code) {
            return searchHelper(node->left, key);
        } else {
            return searchHelper(node->right, key);
        }
    }

	// RECURSIVELY DELETES NODE IN BINARY SEARCH TREE STARTING FROM THE GIVEN NODE
	// WE ARE USING POST ORDER TRAVERSAL FASHION TO ENSURE COMPLETE DELETION OF NODE
	// INCLUDING ROOT NODE
    void destroyHelper(Node* node) {
        if (node != nullptr) {
            destroyHelper(node->left);
            destroyHelper(node->right);
            delete node->data;
            delete node;
        }
    }

public:
    BinarySearchTree() : root(nullptr) {}

    ~BinarySearchTree() {
        destroyHelper(root);
    }

    void insert(TreeNode* item) {
        insertHelper(root, item);
    }

    TreeNode* search(const std::string& key) {
        return searchHelper(root, key);
    }
};

#endif // BINARY_SEARCH_TREE_HPP

