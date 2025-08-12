#include <stdio.h>
#include <stdlib.h>
void decimalToBinary(int num, char *binary, int index) {
    if(index<0) return;
    decimalToBinary(num/2,binary,index-1);
    binary[index]=(num%2)+'0';
}

int main(int argc,char *argv[]) {
    int n=atoi(argv[1]);
    FILE *ifptr=fopen(argv[2], "r");
    if(!ifptr){
        perror("Error opening source file");
        return 1;
    }
    FILE *ofptr=fopen(argv[3], "w");
    if(!ofptr){
        perror("Error opening destination file");
        fclose(ifptr);
        return 1;
    }
    int num,count=0;
    while(count<n && fscanf(ifptr, "%d", &num)==1){
        char binary[17]={0};
        decimalToBinary(num,binary,15);
        binary[16]='\0';
        fprintf(ofptr, "The binary equivalent of %d is %s\n", num, binary);
        count++;
    }
    ofptr=fopen(argv[3], "r");
    if(!ofptr){
        perror("Error opening destination file for reading");
        return 1;
    }

    char line[256];
    while (fgets(line, sizeof(line), ofptr)){
        printf("%s", line);
    }
    return 0;
}