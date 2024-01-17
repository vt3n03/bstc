// CS2211a 2023, Section 1
// Assignment 4
// Victor Tan
// 251 222 810
// VTAN29
// 2023/11/15
#ifndef DATA_H
#define DATA_H

// Structure for key
typedef struct
{
  char *name;  // Name associated with the key
  int id;      // ID associated with the key
} Key;

typedef int Data;  // Typedef for data associated with a node

// Structure for Node
typedef struct
{
  Key *key;     // Pointer to the key structure
  Data data;    // Data associated with the node
  int left, right;  // Indices of the left and right children in the array
} Node;

// Construct a new Key with the given name and ID
Key * key_construct (char *in_name, int in_id);

// Compare two keys lexicographically
int key_comp (Key * key1, Key * key2);

// Print the details of a key
void print_key (Key * key);

// Print the details of a node
void print_node (Node node);

// Helper method to create a new node with the given key, data, left, and right indices
Node newNode(Key * key, Data data, int left, int right);

#endif /* DATA_H */
