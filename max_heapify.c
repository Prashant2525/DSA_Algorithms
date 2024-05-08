#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void heapify(int heap[], int n, int i)
{
    int root = i;
    int l = (2 * i) + 1;
    int r = (2 * i) + 2;

    while (l < n && heap[l] > heap[root])
    {
        root = l;
    }
    while (r < n && heap[r] > heap[root])
    {
        root = r;
    }
    if (root != i)
    {
        int t = heap[root];
        heap[root] = heap[i];
        heap[i] = t;
        heapify(heap, n, root);
    }
}

void build_heap(int heap[], int n)
{
    // Index of last non-leaf node
    int last_non_leaf_node = (n / 2) - 1; // If we start from 0...1....2   for 1....2....3 we do (n / 2) + 1

    // Perform level order traversal in reverse from last non-leaf node to the root node and heapify each node
    for (int i = last_non_leaf_node; i >= 0; i--)
    {
        heapify(heap, n, i);
    }
}

void display(int heap[], int n)
{
    printf("\nPrinting heap: ");
    for (int j = 0; j < n; j++)
    {
        printf("%d ", heap[j]);
    }
    printf("\n");
}

int main()
{
    int n;

    printf("\nEnter the size of an array: ");
    scanf("%d", &n);

    int *heap;

    heap = (int *)malloc(n * sizeof(int));

    printf("Enter a value to insert into the binary heap: ");

    for (int i = 0 ; i < n ; i++)
    {
        scanf("%d", &heap[i]);
    }

    build_heap(heap, n);

    display(heap, n);
    return 0;
}
