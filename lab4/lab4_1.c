#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define MAX 1000 

long long comparisons=0;

void merge(int arr[],int left,int mid,int right) {
    int n1=mid-left+1;
    int n2=right-mid;
    int L[n1], R[n2];
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i=0, j=0, k=left;
    while (i<n1 && j<n2) {
        comparisons++;
        if (L[i] <= R[j])
            arr[k++]=L[i++];
        else
            arr[k++]=R[j++];
    }
    while (i<n1)
        arr[k++]=L[i++];
    while (j<n2)
        arr[k++]=R[j++];
}

void mergeSort(int arr[], int left, int right) {
    if (left<right) {
        int mid = floor((left+right)/2);
        mergeSort(arr,left,mid);
        mergeSort(arr,mid+1,right);
        merge(arr,left,mid,right);
    }
}

int readFile(const char *inAsce, int arr[]) {
    FILE *fp=fopen("inAsce.dat", "r");
    if (!fp) {
        printf("Error opening file %s\n", inAsce);
        return -1;
    }
    int count = 0;
    while (fscanf(fp, "%d",&arr[count])==1) {
        count++;
    }
    fclose(fp);
    return count;
}

void writeFile(const char *outAsce, int arr[], int n) {
    FILE *fp = fopen("outAsce.dat", "w");
    if (!fp) {
        printf("Error writing to file %s\n", outAsce);
        return;
    }
    for (int i=0; i<n;i++) {
        fprintf(fp, "%d ",arr[i]);
    }
    fclose(fp);
}

int main() {
    int choice;
    int arr[MAX], n;
    char inFile[50], outFile[50];
    while (1) {
        printf("\nMAIN MENU (MERGE SORT)\n");
        printf("1. Ascending Data\n");
        printf("2. Descending Data\n");
        printf("3. Random Data\n");
        printf("4. EXIT\n");
        printf("Enter option: ");
        scanf("%d", &choice);
        if (choice == 4) break;

        switch(choice){
            case 1:
                snprintf(inFile, sizeof(inFile), "inAsce.dat");
                snprintf(outFile, sizeof(outFile), "outMergeAsce.dat");
                break;
            case 2:
                snprintf(inFile, sizeof(inFile), "inDesc.dat");
                snprintf(outFile, sizeof(outFile), "outMergeDesc.dat");
                break;
            case 3:
                snprintf(inFile, sizeof(inFile), "inRand.dat");
                snprintf(outFile, sizeof(outFile), "outMergeRand.dat");
                break;
            default:
                printf("Invalid choice!\n");
                continue;
        }

        n=readFile(inFile, arr);
        if (n <= 0) continue;

        printf("Before Sorting:\n");
        for (int i = 0; i < n; i++)
            printf("%d ", arr[i]);
        printf("\n");

        comparisons = 0;

        printf("After Sorting:\n");
        for (int i = 0; i < n; i++)
            printf("%d ", arr[i]);
        printf("\n");

        writeFile(outFile, arr, n);

        printf("Number of Comparisons: %lld\n", comparisons);
    }

    return 0;
}