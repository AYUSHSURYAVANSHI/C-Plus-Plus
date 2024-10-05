/**
 * @file morris_inorder_traversal.cpp
 * @brief C++ implementation of Morris In-order Traversal for Binary Trees.
 * 
 * This program performs in-order traversal of a binary tree without using 
 * recursion or a stack, achieving O(1) space complexity using Morris Traversal.
 * 
 * The program includes an example of how to create a binary tree and run the 
 * traversal, with test cases for correctness. 
 * 
 * @author AYUSHSURYAVANSHI
 * @date 2024-10-05
 */

#include <iostream>
using namespace std;

/**
 * @brief Definition of the TreeNode structure.
 * 
 * This structure represents a node in the binary tree, with a value, 
 * a left child, and a right child.
 */
struct TreeNode {
    int val;          ///< Value of the node
    TreeNode* left;   ///< Pointer to the left child
    TreeNode* right;  ///< Pointer to the right child

    /**
     * @brief Constructor for TreeNode.
     * @param value The value to initialize the node with.
     */
    TreeNode(int value) : val(value), left(nullptr), right(nullptr) {}
};

/**
 * @brief Function to perform Morris In-order Traversal on a binary tree.
 * 
 * This function prints the nodes of the binary tree in in-order traversal
 * without using recursion or additional stack space. The tree is temporarily 
 * modified during the traversal but restored to its original structure afterward.
 * 
 * @param root Pointer to the root node of the binary tree.
 */
void morrisInOrderTraversal(TreeNode* root) {
    TreeNode* current = root;

    while (current != nullptr) {
        if (current->left == nullptr) {
            // Print the current node value
            cout << current->val << " ";
            // Move to the right child
            current = current->right;
        } else {
            // Find the in-order predecessor of current
            TreeNode* predecessor = current->left;
            while (predecessor->right != nullptr && predecessor->right != current) {
                predecessor = predecessor->right;
            }

            if (predecessor->right == nullptr) {
                // Establish a temporary link to the current node
                predecessor->right = current;
                current = current->left;
            } else {
                // Revert the changes made in the tree structure
                predecessor->right = nullptr;
                cout << current->val << " ";
                current = current->right;
            }
        }
    }
}

/**
 * @brief A simple test case to verify the functionality of Morris In-order Traversal.
 * 
 * This function constructs a sample binary tree, runs the traversal, and
 * outputs the result to verify correctness.
 */
void testMorrisTraversal() {
    // Create a sample binary tree:
    //       1
    //      / \
    //     2   3
    //    / \
    //   4   5
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    // Expected in-order output: 4 2 5 1 3
    cout << "Morris In-order Traversal: ";
    morrisInOrderTraversal(root);
    cout << endl;
}

/**
 * @brief Main function to run the Morris In-order Traversal example and test cases.
 * 
 * The main function serves as an entry point for the program, demonstrating
 * the Morris traversal with a test case.
 * 
 * @return int Exit status of the program.
 */
int main() {
    testMorrisTraversal();
    return 0;
}
