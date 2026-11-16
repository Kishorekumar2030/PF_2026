#include <stdio.h>

int sum(int n) {
    if (n <= 1) {
        return n;
    }
        return n%10 + sum(n/10);
    }


int main() {
    int num ;
    printf("enter your numb:");
    scanf("%d",&num);
  printf("%d",sum(num));




    return 0;
}