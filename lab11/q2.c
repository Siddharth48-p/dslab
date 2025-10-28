#include <stdio.h>
#include <stdlib.h>

struct Node {
    int vertex;
    struct Node* next;
};

struct Node* adjList[20];

struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

void addEdge(int src, int dest, int type) {
    struct Node* newNode = createNode(dest);
    newNode->next = adjList[src];
    adjList[src] = newNode;

    if (type == 2) {
        newNode = createNode(src);
        newNode->next = adjList[dest];
        adjList[dest] = newNode;
    }
}

void display(int n) {
    for (int i = 0; i < n; i++) {
        struct Node* temp = adjList[i];
        printf("Vertex %d: ", i);
        while (temp) {
            printf("-> %d ", temp->vertex);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main() {
    int n, e, type, src, dest;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter number of edges: ");
    scanf("%d", &e);
    printf("1. Directed Graph\n2. Undirected Graph\nEnter choice: ");
    scanf("%d", &type);

    for (int i = 0; i < n; i++)
        adjList[i] = NULL;

    printf("Enter edges (source destination):\n");
    for (int i = 0; i < e; i++) {
        scanf("%d %d", &src, &dest);
        addEdge(src, dest, type);
    }

    printf("Adjacency List:\n");
    display(n);

    return 0;
}
