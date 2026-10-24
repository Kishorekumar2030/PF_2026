
#include<stdio.h>

int add(int a,int b,int *result){
    *result=a+b;
    return 1;
}

int subtract(int a,int b,int *result){
    *result=a-b;
    return 1;
}

int multiply(int a,int b,int *result){
    *result=a*b;
    return 1;
}

int divide(int a,int b,int *result){
    if(b==0){
        return 0;
    }

    *result=a/b;
    return 1;
}

int main(){
    int (*ops[])(int,int,int *)={add,subtract,multiply,divide};
    const char *names[]={"Add","Subtract","Multiply","Divide"};

    int choice,a,b,result;

    while(1){
        printf("\n1. %s\n",names[0]);
        printf("2. %s\n",names[1]);
        printf("3. %s\n",names[2]);
        printf("4. %s\n",names[3]);
        printf("5. Exit\n");

        printf("Choice (1-5): ");
        scanf("%d",&choice);

        if(choice==5){
            printf("Goodbye.\n");
            break;
        }

        if(choice<1 || choice>5){
            printf("Invalid choice\n");
            continue;
        }

        printf("Enter two numbers: ");
        scanf("%d%d",&a,&b);

        if(ops[choice-1](a,b,&result)==1){
            printf("Result: %d\n",result);
        }
        else{
            printf("Error: Division by zero.\n");
        }
    }

    return 0;
}
