#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_TREE_HT 100
typedef struct MinHeapNode {
    char data; 
    unsigned freq; 
    struct MinHeapNode *left, *right; 
} MinHeapNode;
typedef struct MinHeap {
    unsigned size; 
    unsigned capacity; 
    MinHeapNode **array; 
} MinHeap;
MinHeapNode* createNode(char data, unsigned freq) {
    MinHeapNode *node = (MinHeapNode*)malloc(sizeof(MinHeapNode));
    node->left = node->right = NULL;
    node->data = data;
    node->freq = freq;
    return node;
}
MinHeap* createMinHeap(unsigned capacity) {
    MinHeap *minHeap = (MinHeap*)malloc(sizeof(MinHeap));
    minHeap->size = 0;
    minHeap->capacity = capacity;
    minHeap->array = (MinHeapNode**)malloc(minHeap->capacity * sizeof(MinHeapNode*));
    return minHeap;
}
void swapMinHeapNode(MinHeapNode** a, MinHeapNode** b) {
    MinHeapNode* temp = *a;
    *a = *b;
    *b = temp;
}
void minHeapify(MinHeap *minHeap, int idx, int *step_count) {
    (*step_count)++; 
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    if (left < minHeap->size && minHeap->array[left]->freq < minHeap->array[smallest]->freq)
        smallest = left;

    if (right < minHeap->size && minHeap->array[right]->freq < minHeap->array[smallest]->freq)
        smallest = right;

    if (smallest != idx) {
        swapMinHeapNode(&minHeap->array[smallest], &minHeap->array[idx]);
        minHeapify(minHeap, smallest, step_count);
    }
}
int isSizeOne(MinHeap *minHeap) {
    return (minHeap->size == 1);
}
MinHeapNode* extractMin(MinHeap *minHeap, int *step_count) {
    (*step_count)++; 
    MinHeapNode *temp = minHeap->array[0];
    minHeap->array[0] = minHeap->array[minHeap->size - 1];
    --minHeap->size;
    minHeapify(minHeap, 0, step_count);
    return temp;
}
void insertMinHeap(MinHeap *minHeap, MinHeapNode *minHeapNode, int *step_count) {
    (*step_count)++; 
    ++minHeap->size;
    int i = minHeap->size - 1;
    while (i && minHeapNode->freq < minHeap->array[(i - 1) / 2]->freq) {
        minHeap->array[i] = minHeap->array[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    minHeap->array[i] = minHeapNode;
}
void buildMinHeap(MinHeap *minHeap, int *step_count) {
    int n = minHeap->size - 1;
    for (int i = (n - 1) / 2; i >= 0; --i)
        minHeapify(minHeap, i, step_count);
}
int isLeaf(MinHeapNode *root) {
    return !(root->left) && !(root->right);
}
void printCodes(MinHeapNode *root, int arr[], int top, int *step_count) {
    (*step_count)++; 
    if (root->left) {
        arr[top] = 0;
        printCodes(root->left, arr, top + 1, step_count);
    }
    if (root->right) {
        arr[top] = 1;
        printCodes(root->right, arr, top + 1, step_count);
    }
    if (isLeaf(root)) {
        printf("%c: ", root->data);
        for (int i = 0; i < top; ++i)
            printf("%d", arr[i]);
        printf("\n");
    }
}
void HuffmanCodes(char data[], int freq[], int size, int *step_count) {
    MinHeapNode *left, *right, *top;
    MinHeap *minHeap = createMinHeap(size);
    for (int i = 0; i < size; ++i) {
        minHeap->array[i] = createNode(data[i], freq[i]);
        minHeap->size++;
    }

    buildMinHeap(minHeap, step_count);
    while (!isSizeOne(minHeap)) {
        left = extractMin(minHeap, step_count);
        right = extractMin(minHeap, step_count);

        top = createNode('$', left->freq + right->freq);
        top->left = left;
        top->right = right;

        insertMinHeap(minHeap, top, step_count);
    }
    int arr[MAX_TREE_HT], topIdx = 0;
    printCodes(extractMin(minHeap, step_count), arr, topIdx, step_count);
}
main() 
{
    char data[] = { 'a', 'b', 'c', 'd', 'e', 'f' };
    int freq[] = { 5, 9, 12, 13, 16, 45 };
    int size = sizeof(data) / sizeof(data[0]);
    int steps = 0;
    HuffmanCodes(data, freq, size, &steps);
    printf("Total number of steps: %d\n", steps);
}

