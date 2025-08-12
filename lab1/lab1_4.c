#include<stdio.h>
int main(){
    FILE *fptr=NULL;
    fptr=fopen("test.txt","r");
    int n;
    fscanf(fptr,"%d",&n);
    if(fptr!=NULL){
    int arr[n];
    for(int i=0;i<n;i++){
        fscanf(fptr,"%d",&arr[i]);
    }
    int p1,p2;
    fscanf(fptr,"%d",&p1);
    fscanf(fptr,"%d",&p2);
    int temp=arr[p1+p2-1];
    for(int i=p1+p2-1;i>=p1;i--){
        arr[i]=arr[i-1];
    }
    arr[p1]=temp;
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
}
}