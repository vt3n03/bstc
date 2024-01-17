// CS2211a 2023, Section 1
// Assignment 4
// Victor Tan
// 251 222 810
// VTAN29
// 2023/11/15

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "data.h"

// Function to construct a new key with the given name and ID
// Allocates memory for the key and duplicates the name string
Key *key_construct(char *in_name, int in_id) {
    Key *newKey = (Key *)malloc(sizeof(Key));
    if (newKey != NULL) {
        newKey->name = strdup(in_name);  // Allocate and copy the string
        newKey->id = in_id;
    }
    return newKey;
}

// Function to create a new node with the given key, data, left, and right indices
// Returns the created node
Node newNode(Key *key, Data data, int left, int right) {
    Node n;
    n.key = key;  // Assuming key is already a valid pointer
    n.data = data;
    n.left = left;
    n.right = right;
    return n;
}

// Function to compare two keys for sorting in a BST
// Returns a negative value if key1 is smaller, positive if key2 is smaller, and 0 if equal
int key_comp(Key *key1, Key *key2) {
    int stringComparison = strcasecmp(key1->name, key2->name);

    if (stringComparison == 0) {
        // If strings are equal, compare IDs
        return key1->id - key2->id;
    }

    return stringComparison;
}

// Function to print the details of a key
void print_key(Key *key) {
    if (key != NULL) {
        printf("%-3d %-50s", key->id, key->name);
    } else {
        printf("NULL key");
    }
}

// Function to print the details of a node, including key and associated data
void print_node(Node node) {
    if (node.key != NULL) {
        printf("%-3d %-50s %-8d\n", node.key->id, node.key->name, node.data);
    } else {
        printf("Node key is NULL\n");
    }
}
