#include<stdio.h>
int main(){
int marks[5];

for(int i=0;i<5;i++){
    printf("Marks of studen%d:",i+1);
    scanf("%d",&marks[i]);
    if(marks[i]>100 || marks[i]<0){
        printf("invalid marks:\n");
        printf("enter marks again:\n");
        i--;
    }
}
int max=marks[0],min=marks[0];
for(int j=0;j<5;j++){
    if (marks[j]>max){
        max=marks[j];}
    if(marks[j]<min){
        min=marks[j];
    }
}


printf("max is :%d \n",max);
printf("min is :%d",min);
}
