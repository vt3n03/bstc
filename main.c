// CS2211a 2023, Section 1
// Assignment 4
// Victor Tan
// 251 222 810
// VTAN29
// 2023/11/15
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bst.h"

int main(int argc, char *argv[]) {
    FILE *inputFile;
    int size;

    // Check if a filename is provided as a command-line argument
    if (argc == 2) {
        // Open the file for reading
        inputFile = fopen(argv[1], "r");
        if (inputFile == NULL) {
            fprintf(stderr, "Error opening file: %s\n", argv[1]);
            return 1;
        }

        // Read the size from the file
        fscanf(inputFile, "%d%*c", &size);

        // Consume the newline character after reading the size
        printf("Size read from file: %d\n", size);
        // Check if the size is 0, and terminate the program if true
        if (size == 0) {
            fprintf(stderr, "Error: Tree size cannot be 0.\n");
            exit(1);          // Terminate the program with an error code
        }
    } else if (argc == 1) {
        // No command-line argument provided, read from stdin
        printf("Enter the size of the tree node array: ");
        scanf("%d", &size);
        if (size == 0) {
            fprintf(stderr, "Error: Tree size cannot be 0.\n");
            exit(1);          // Terminate the program with an error code
        }
        getchar();  // Consume the newline character

        // Set inputFile to stdin
        inputFile = stdin;
    } else {
        // Incorrect usage
        fprintf(stderr, "Usage: %s [filename]\n", argv[0]);
        return 1;
    }

    // Initialize binary search tree
    BStree bst = bstree_ini(size);

    // Read key and data pairs from the user or file
    int keyNumber;
    char str[256];
    int data;

    while (1) {
        if (inputFile == stdin) {
            printf("Enter key (int followed by a string with spaces, or -1 to finish): ");
        }
        // Read key and keyString together
        int result = fscanf(inputFile, "%d", &keyNumber);

        // Check if the user wants to finish
        if (keyNumber == -1 || result == EOF) {
            break;
        }
        // Consume any remaining spaces after the first int
        int c;
        while ((c = fgetc(inputFile)) != EOF && c != '\n' && c == ' ');

        // Append the first character after whitespace (if any) to the string
        size_t i = 0;
        str[i++] = (char)c;
        // Read the rest of the line using fgets
        while (i < sizeof(str) - 1 && (c = fgetc(inputFile)) != EOF && c != '\n') {
            str[i++] = (char)c;
        }
        str[i] = '\0';  // Null-terminate the string

        // Read data
        // Check if reading from standard input before printing data prompt
        if (inputFile == stdin) {
            printf("Enter data (int): ");
        }
        fscanf(inputFile, "%d%*c", &data);

        // Insert key and data into the binary search tree
        bstree_insert(bst, key_construct(str, keyNumber), data);
    }

    // Perform traversal
    bstree_traversal(bst);

    // Close the file if it's not stdin
    if (argc == 2) {
        fclose(inputFile);
    }

    // Free the binary search tree
    bstree_free(bst);

    return 0;
}
