#include <stdio.h>
#include <stdlib.h>
#define INF 999999

int main() {
    int n, start;
    FILE *fp;
    fp=fopen("inUnAdjMat.dat", "r");
    if (!fp) {
        printf("Error opening file!\n");
        return 1;
    }

    int temp,count = 0;
    char ch;
    while ((ch=fgetc(fp))!='\n' && ch!=EOF) {
        if(ch==' ')continue;
        ungetc(ch, fp);
        fscanf(fp, "%d", &temp);
        count++;
    }
    rewind(fp);
    n=count;
    int cost[n][n];
    for (int i=0;i<n;i++)
        for (int j=0;j<n;j++) {
            fscanf(fp,"%d",&cost[i][j]);
            if (cost[i][j]==0 && i!=j)
                cost[i][j]=INF;
    }

    fclose(fp);
    printf("Enter the Starting Vertex: ");
    scanf("%d",&start);
    start--;
    int selected[n];
    int key[n];
    int parent[n];
    
    for (int i=0;i<n;i++) {
        key[i]=INF;
        selected[i]=0;
        parent[i]=-1;
    }
    key[start]=0;

    for (int count=0;count<n-1;count++) {
        int u=-1;
        for (int i=0;i<n;i++)
            if (!selected[i] && (u==-1 || key[i]<key[u]))
                u = i;

        selected[u]=1;

        for (int v=0;v<n;v++) {
            if (cost[u][v]!=INF && !selected[v] && cost[u][v]<key[v]) {
                key[v]=cost[u][v];
                parent[v]=u;
            }
        }
    }

    int mst[n][n];
    for (int i=0;i<n;i++)
        for (int j=0;j<n;j++)
            mst[i][j]=0;

    int total_cost=0;
    for (int i=0;i<n;i++) {
        if (parent[i]!=-1) {
            mst[i][parent[i]] = mst[parent[i]][i] = cost[i][parent[i]];
            total_cost += cost[i][parent[i]];
        }
    }

    printf("Cost Adjacency Matrix of MST:\n");
    for (int i=0;i<n;i++) {
        for (int j=0;j<n;j++)
            if (mst[i][j]==INF) printf("0 ");
            else printf("%d ", mst[i][j]);
        printf("\n");
    }

    printf("Total Weight of the Spanning Tree: %d\n", total_cost);

    return 0;
}
