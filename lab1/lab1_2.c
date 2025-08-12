#include<stdio.h>
int main(){
    FILE *fptr=NULL;
    fptr=fopen("test.txt","r");
    int n;
    fscanf(fptr,"%d",&n);
    if(fptr!=NULL){
    int arr[n];
    int ans[n];
    for(int i=0;i<n;i++){
        fscanf(fptr,"%d",&arr[i]);
    }
    ans[0]=arr[0];// 10 20 30 40
    for(int i=1;i<n;i++){
        ans[i]=arr[i-1]+arr[i];
    }
    printf("The prefix sum array is:\n");
    for(int i=0;i<n;i++){
        printf("%d ",ans[i]);
    }

}
else printf("\nError opening the file");
}