// Data structure used in "Patient Cabin Managment" is "Binary Search Tree"
// This Header file Contains implementation of "Binary Search Tree"
#ifndef BST_HPP
#define BST_HPP

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>  
#include <ctime>    

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
    std::vector<TreeNode*> nodes;  // Store pointers to all nodes for random selection

    // Helper function to insert data into the BST
    void insertHelper(Node*& node, TreeNode* item) {
        if (node == nullptr) {
            node = new Node(item);
            nodes.push_back(item);  // Add the node to the vector for random access
        } else if (item->cabin_code < node->data->cabin_code) {
            insertHelper(node->left, item);
        } else {
            insertHelper(node->right, item);
        }
    }

    // Helper function to search for a cabin in the BST
    TreeNode* searchHelper(Node* node, const std::string& key) {
        if (node == nullptr || node->data->cabin_code == key) {
            return (node == nullptr) ? nullptr : node->data;
        } else if (key < node->data->cabin_code) {
            return searchHelper(node->left, key);
        } else {
            return searchHelper(node->right, key);
        }
    }

    // Helper function to destroy the BST
    void destroyHelper(Node* node) {
        if (node != nullptr) {
            destroyHelper(node->left);
            destroyHelper(node->right);
            delete node->data;
            delete node;
        }
    }

public:
    // Constructor initializes the BST with predefined cabins and seeds the random generator
    BinarySearchTree() : root(nullptr) {
        std::srand(static_cast<unsigned>(std::time(0))); // Seed random number generator

        // Insert predefined cabins
        insert(new TreeNode("CAB001", true));
        insert(new TreeNode("CAB002", true));
        insert(new TreeNode("CAB003", true));
        insert(new TreeNode("CAB004", true));
        insert(new TreeNode("CAB005", true));
    }

    ~BinarySearchTree() {
        destroyHelper(root);
    }

    void insert(TreeNode* item) {
        insertHelper(root, item);
    }

    TreeNode* search(const std::string& key) {
        return searchHelper(root, key);
    }

    // Function to randomly select a cabin
    TreeNode* getRandomCabin() {
        if (nodes.empty()) {
            return nullptr;
        }

        int randomIndex = std::rand() % nodes.size();
        return nodes[randomIndex];
    }
};

#endif // BINARY_SEARCH_TREE_HPP
