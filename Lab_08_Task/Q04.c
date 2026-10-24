#include <stdio.h>
int main(){
    int steps;
    int totalsteps=0,count=0;
    float ave;
    for(int i=0;i<7;i++){
        printf("steps of day %d:",i+1);
        scanf("%d",&steps);
        totalsteps=totalsteps+steps;
        if(steps>8000){
            count=count+1;
        }
    }
    ave=totalsteps/7;
    printf("ave steps:%.2f\n",ave);
    printf("days reached goal:%d:",count);


}
