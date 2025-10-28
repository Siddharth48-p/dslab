#include <stdio.h>

int adj[20][20], visited[20], n;

void dfs(int v) {
    visited[v] = 1;
    printf("%d ", v);
    for (int i = 0; i < n; i++) {
        if (adj[v][i] == 1 && visited[i] == 0)
            dfs(i);
    }
}

int main() {
    int e, i, j, src, dest, start;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter number of edges: ");
    scanf("%d", &e);

    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            adj[i][j] = 0;

    printf("Enter edges (source destination):\n");
    for (i = 0; i < e; i++) {
        scanf("%d %d", &src, &dest);
        adj[src][dest] = adj[dest][src] = 1;
    }

    for (i = 0; i < n; i++)
        visited[i] = 0;

    printf("Enter starting vertex: ");
    scanf("%d", &start);

    printf("DFS Traversal: ");
    dfs(start);
    printf("\n");

    return 0;
}
