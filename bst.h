// CS2211a 2023, Section 1
// Assignment 4
// Victor Tan
// 251 222 810
// VTAN29
// 2023/11/15

#ifndef BST_H
#define BST_H

#include "data.h"

// Structure for sorted nodes
typedef struct {
    Node *nodes;    // Array of nodes
    int index;      // Index indicating the current position in the array
} SortedNodes;

typedef struct {
    Node *tree_nodes;           // Array of tree nodes
    unsigned int *free_nodes;   // Array to keep track of free node indices
    int size;                   // Maximum size of the tree
    int top;                    // Index of the next available node in the array
    int root;                   // Index of the root node in the array
} BStree_struct;

typedef BStree_struct* BStree;  // Pointer to the Binary Search Tree structure

// Function to initialize a binary search tree with the given size
BStree bstree_ini(int size);

// Function to insert a new node into the binary search tree
void bstree_insert(BStree bst, Key *key, Data data);

// Helper function for inorder traversal of the binary search tree
void bstree_traversal_helper(BStree bst, int node_index);

// Function to perform inorder traversal of the binary search tree
void bstree_traversal(BStree bst);

// Function to free the memory allocated for the binary search tree
void bstree_free(BStree bst);

#endif /* BST_H */
