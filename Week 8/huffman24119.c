// CH.SC.U4CSE24119 - KAVIN J S

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHAR 256
#define MAX_TREE_HT 100

// Huffman Tree Node
struct Node {
    char data;
    int freq;
    struct Node *left, *right;
};

// Create new node
struct Node* createNode(char data, int freq) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->freq = freq;
    node->left = node->right = NULL;
    return node;
}

// Simple priority queue using array
void sortNodes(struct Node* arr[], int n) {
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (arr[i]->freq > arr[j]->freq) {
                struct Node* temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
}

// Print Huffman Codes
void printCodes(struct Node* root, int code[], int top,
                int *originalBits, int *compressedBits) {

    if (root->left) {
        code[top] = 0;
        printCodes(root->left, code, top + 1,
                   originalBits, compressedBits);
    }

    if (root->right) {
        code[top] = 1;
        printCodes(root->right, code, top + 1,
                   originalBits, compressedBits);
    }

    if (!root->left && !root->right) {
        printf("  %c   |   %3d   | ", root->data, root->freq);

        for (int i = 0; i < top; i++)
            printf("%d", code[i]);

        printf("\n");

        *originalBits += root->freq * 8;
        *compressedBits += root->freq * top;
    }
}

int main() {

    printf("CH.SC.U4CSE24119 - KAVIN J S\n");

    char str[1000];
    int freq[MAX_CHAR] = {0};

    printf("Enter string: ");
    scanf("%s", str);

    // Count frequency
    for (int i = 0; str[i] != '\0'; i++)
        freq[(unsigned char)str[i]]++;

    struct Node* nodes[MAX_CHAR];
    int n = 0;

    // Store unique characters
    for (int i = 0; i < MAX_CHAR; i++)
        if (freq[i] > 0)
            nodes[n++] = createNode(i, freq[i]);

    // Build Huffman Tree
    while (n > 1) {

        sortNodes(nodes, n);

        struct Node* left = nodes[0];
        struct Node* right = nodes[1];

        struct Node* newNodeMerged =
            createNode('$', left->freq + right->freq);

        newNodeMerged->left = left;
        newNodeMerged->right = right;

        nodes[0] = newNodeMerged;
        nodes[1] = nodes[n - 1];
        n--;
    }

    printf("\nChar | Freq | Huffman Code\n");
    printf("--------------------------\n");

    int code[MAX_TREE_HT];
    int originalBits = 0, compressedBits = 0;

    printCodes(nodes[0], code, 0,
               &originalBits, &compressedBits);

    printf("\nOriginal size: %d bits\n", originalBits);
    printf("Compressed size: %d bits\n", compressedBits);
    printf("Space saved: %d bits (%.2f%%)\n",
           originalBits - compressedBits,
           ((float)(originalBits - compressedBits) /
            originalBits) * 100);

    return 0;
}
