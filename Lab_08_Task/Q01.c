
#include<stdio.h>
void bubbleSort(int *arr,int n){
    int temp;
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(*(arr+j)>*(arr+j+1)){
                temp=*(arr+j);
                *(arr+j)=*(arr+j+1);
                *(arr+j+1)=temp;
            }
        }
    }
}
void printArray(const int *arr,int n){
    for(int i=0;i<n;i++){
        printf("%d ",*(arr+i));
    }
    printf("\n");
}
int main(){
    int n_of_scores;
    printf("Enter number of scores: ");
    scanf("%d",&n_of_scores);
    while(n_of_scores<1 || n_of_scores>20){
        printf("Invalid size\n");
        printf("Enter number of scores: ");
        scanf("%d",&n_of_scores);
    }
    int score[n_of_scores];
    printf("Enter scores: ");
    for(int i=0;i<n_of_scores;i++){
        scanf("%d",&score[i]);
    }
    printf("Before sorting: ");
    printArray(score,n_of_scores);
    bubbleSort(score,n_of_scores);
    printf("After sorting: ");
    printArray(score,n_of_scores);
    return 0;
}
