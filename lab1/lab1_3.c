#include<stdio.h>
int main(){
    int c=0,dup=0,mostoccurring=0;;
    for(int i=0;i<n;i++){
        int count=0;
        for(int j=i;j>=0;j--){
            if(arr[i]==arr[j])count++;
        }
        if(count!=0)dup++;
        if(count>c){
            c=count;
            mostoccurring=arr[i];
        }
    }
    printf("Total number of duplicate is:%d",dup);
    printf("\nMost repeating element is %d",mostoccurring);

}
}