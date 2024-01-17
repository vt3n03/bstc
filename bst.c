// CS2211a 2023, Section 1
// Assignment 4
// Victor Tan
// 251 222 810
// VTAN29
// 2023/11/15
#include <stdio.h>
#include <stdlib.h>
#include "bst.h"

// Function to create a new node in the binary search tree
Node *create_node(Key *key, Data data, int left, int right) {
    Node *n = (Node *)malloc(sizeof(Node));
    if (n != NULL) {
        n->key = key;  // Store the key directly
        n->data = data;
        n->left = left;
        n->right = right;
    }
    return n;
}

// Function to insert a node into the binary search tree
void bst_insert(BStree bst, int node_index, Key *key, Data data) {
    if (node_index >= bst->size) {
        printf("The tree is full. No more nodes can be added.\n");
        return;
    }

    if (bst->tree_nodes[node_index].key == NULL) {
        // The current node is empty, insert the new node here
        bst->tree_nodes[node_index].key = key;  // Store the key directly
        bst->tree_nodes[node_index].data = data;
        bst->tree_nodes[node_index].left = 0;
        bst->tree_nodes[node_index].right = 0;
    } else {
        int cmp = key_comp(key, bst->tree_nodes[node_index].key);
        if (cmp <= 0) {
            // Key is smaller or equal, go to the left subtree
            if (bst->tree_nodes[node_index].left == 0) {
                // Left child is empty, insert the new node here
                bst->tree_nodes[node_index].left = bst->top;
                bst->tree_nodes[bst->top] = *create_node(key, data, 0, 0);
                bst->top++;
            } else {
                // Left child is not empty, recurse to the left subtree
                bst_insert(bst, bst->tree_nodes[node_index].left, key, data);
            }
        } else {
            // Key is greater, go to the right subtree
            if (bst->tree_nodes[node_index].right == 0) {
                // Right child is empty, insert the new node here
                bst->tree_nodes[node_index].right = bst->top;
                bst->tree_nodes[bst->top] = *create_node(key, data, 0, 0);
                bst->top++;
            } else {
                // Right child is not empty, recurse to the right subtree
                bst_insert(bst, bst->tree_nodes[node_index].right, key, data);
            }
        }
    }
}

// Function to initialize a binary search tree
BStree bstree_ini(int size) {
    BStree tree = (BStree)malloc(sizeof(BStree_struct));
    // Initialize pointers for dynamic memory allocation
    Node *treeNodes;
    unsigned int *freeNodes;
    // Dynamic Memory Allocation
    treeNodes = (Node *)malloc((size + 1) * sizeof(Node));
    freeNodes = (unsigned int *)malloc((size + 1) * sizeof(unsigned int));
    // Fill freeNodes
    for (int i = 0; i < size + 1; i++) {
        freeNodes[i] = i;
    }
    // Set values in BStree
    tree->free_nodes = freeNodes;
    tree->root = 0;
    tree->top = 1;
    tree->size = size;
    tree->tree_nodes = treeNodes;
    return tree;
}

// Function to insert a node into the binary search tree (wrapper function)
void bstree_insert(BStree bst, Key *key, Data data) {
    if (bst->root == 0) {
        // If the tree is empty, insert the new node as the root
        bst->root = bst->top;
        bst->tree_nodes[bst->top] = *create_node(key, data, 0, 0);
        bst->top++;
    } else {
        // If the tree is not empty, call the recursive insert function
        bst_insert(bst, bst->root, key, data);
    }
}

// Helper function for recursive tree traversal
void bstree_traversal_helper(BStree bst, int node_index) {
    if (node_index != 0 && bst->tree_nodes[node_index].key != NULL) {
        // Traverse left subtree
        bstree_traversal_helper(bst, bst->tree_nodes[node_index].left);

        // Print the current node
        print_node(bst->tree_nodes[node_index]);

        // Traverse right subtree
        bstree_traversal_helper(bst, bst->tree_nodes[node_index].right);
    }
}

// Function to perform an in-order traversal of the binary search tree
void bstree_traversal(BStree bst) {
    printf("Starting traversal...\n");
    bstree_traversal_helper(bst, bst->root);
    printf("Traversal complete.\n");
}

// Function to free the memory allocated for the binary search tree
void bstree_free(BStree bst) {
    // Free all dynamically allocated memory for keys
    for (int i = 0; i < bst->top; i++) {
        if (bst->tree_nodes[i].key != NULL) {
            free(bst->tree_nodes[i].key->name);
            free(bst->tree_nodes[i].key);
        }
    }
    // Free the remaining memory
    free(bst->tree_nodes);
    free(bst->free_nodes);
    free(bst);
}
