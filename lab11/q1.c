#include <stdio.h>

int main() {
    int n, e, i, j, src, dest, choice;
    int adj[20][20] = {0};

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &e);

    printf("1. Directed Graph\n2. Undirected Graph\nEnter choice: ");
    scanf("%d", &choice);

    printf("Enter edges (source destination):\n");
    for (i = 0; i < e; i++) {
        scanf("%d %d", &src, &dest);
        adj[src][dest] = 1;
        if (choice == 2)
            adj[dest][src] = 1;
    }

    printf("Adjacency Matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++)
            printf("%d ", adj[i][j]);
        printf("\n");
    }

    return 0;
}
