#include <stdio.h>
#include <stdlib.h>
int gcd(int a,int b) {
    if(b==0)
    return a;
    return gcd(b,a%b);
}
int main(int argc,char *argv[]) {
    FILE *inFile=fopen(argv[1],"r");
    FILE *outFile=fopen(argv[2],"w");
    if (!inFile||!outFile) {
        printf("Error opening file.\n");
        return 1;
    }
    int a,b;
    while (fscanf(inFile,"%d %d",&a,&b)==2) {
        int result=gcd(a, b);
        fprintf(outFile, "The GCD of %d and %d is %d\n", a, b, result);
    }
    outFile=fopen(argv[2], "r");
    if (!outFile){
        printf("Error opening output file.\n");
        return 1;
    }
    char line[100];
    while (fgets(line,sizeof(line),outFile)) {
        printf("%s",line);
    }
    fclose(outFile);
    return 0;
}
