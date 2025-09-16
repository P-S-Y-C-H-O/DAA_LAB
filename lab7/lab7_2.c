#include <stdio.h>
#include <stdlib.h>

struct Edge {
    int u, v, w;
};

int find(int parent[], int i) {
    if (parent[i] != i)
        parent[i] = find(parent, parent[i]);
    return parent[i];
}

void unionSet(int parent[], int rank[], int x, int y) {
    int xroot = find(parent, x);
    int yroot = find(parent, y);
    if (rank[xroot] < rank[yroot])
        parent[xroot] = yroot;
    else if (rank[xroot] > rank[yroot])
        parent[yroot] = xroot;
    else {
        parent[yroot] = xroot;
        rank[xroot]++;
    }
}

int cmpEdges(const void *a, const void *b) {
    return ((struct Edge*)a)->w - ((struct Edge*)b)->w;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    struct Edge edges[m];

    for (int i = 0; i < m; i++)
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w);

    qsort(edges, m, sizeof(struct Edge), cmpEdges);

    int parent[n+1], rank[n+1];
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
        rank[i] = 0;
    }

    int total_cost = 0;
    printf("Edge Cost\n");
    for (int i = 0; i < m; i++) {
        int u = edges[i].u;
        int v = edges[i].v;
        int w = edges[i].w;
        int setU = find(parent, u);
        int setV = find(parent, v);
        if (setU != setV) {
            printf("%d--%d %d\n", u, v, w);
            total_cost += w;
            unionSet(parent, rank, setU, setV);
        }
    }
    printf("Total Weight of the Spanning Tree: %d\n", total_cost);
    return 0;
}
