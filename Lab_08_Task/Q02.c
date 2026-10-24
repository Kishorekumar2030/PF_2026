#include<stdio.h>
void swapvalue(int *A,int *b);
void printswap(const*A,int *b){
    printf("%d%d",*A,*b);
}
int main(){
    void swapvalue(int *A,int *b);
    int swap;
    int *A,*b;
    if(*A>*b){
    swap=*A;
    *A=*b;
    *b=swap;
    printf("enter your value:");
    scanf("%d%d",*A,*b);
}
}