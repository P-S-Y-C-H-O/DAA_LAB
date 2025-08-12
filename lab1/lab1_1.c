#include<stdio.h>
#include <limits.h>
//fputc->
//fputs->adds a file to strings
//fgetc->
//fgets->
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
    int mn=INT_MAX,mx=INT_MIN;
    int slargest=0,ssmallest=0;
    for(int i=0;i<n;i++){
        if(arr[i]>mx){
            slargest=mx;
            mx=arr[i];
        }
        else if(arr[i]>slargest && arr[i]!=mx){
            slargest=arr[i];
        }
    }
    for(int i=0;i<n;i++){
        if(arr[i]<mn){
            ssmallest=mn;
            mn=arr[i];
        }
        else if(arr[i]<ssmallest && arr[i]!=mn){
            ssmallest=arr[i];
        }
    }
    printf("The second largest element is %d\n",slargest);
    printf("The second smallest element is %d\n",ssmallest);
}
else{
    printf("Error opening the file\n");
}
return 0;
}