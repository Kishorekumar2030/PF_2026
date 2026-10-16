#include <stdio.h>
int main(){
    int rows,cols;
    printf("Enter rows: ");
    scanf("%d",&rows);
    printf("Enter columns: ");
    scanf("%d",&cols);
    if(rows<1||rows>5||cols<1||cols>5){
        printf("Invalid matrix size.\n");
        return 0;
    }
    int matrix[rows][cols],matrix2[rows][cols];
    printf("Enter matrix elements:\n");
    for(int i=0;i<rows;i++)
        for(int j=0;j<cols;j++)
            scanf("%d",&matrix[i][j]);
    printf("Matrix:\n");
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++)
            printf("%d ",matrix[i][j]);
        printf("\n");
    }
    // 1. Square and 2. Rectangular
    if(rows==cols)
        printf("1. Square Matrix\n");
    else
        printf("2. Rectangular Matrix\n");
    // 3. Zero Matrix
    int zero=1;
    for(int i=0;i<rows;i++)
        for(int j=0;j<cols;j++)
            if(matrix[i][j]!=0)
                zero=0;
    if(zero)
        printf("3. Zero Matrix\n");
    // 4. Identity Matrix
    if(rows==cols){
        int ok=1;
        for(int i=0;i<rows;i++)
            for(int j=0;j<cols;j++)
                if((i==j&&matrix[i][j]!=1)||(i!=j&&matrix[i][j]!=0))
                    ok=0;
        if(ok)
            printf("4. Identity Matrix\n");
    }
    // 5. Diagonal Matrix
    if(rows==cols){
        int ok=1;
        for(int i=0;i<rows;i++)
            for(int j=0;j<cols;j++)
                if(i!=j&&matrix[i][j]!=0)
                    ok=0;
        if(ok)
            printf("5. Diagonal Matrix\n");
    }
    // 6. Scalar Matrix
    if(rows==cols){
        int ok=1;
        for(int i=0;i<rows;i++)
            for(int j=0;j<cols;j++)
                if((i!=j&&matrix[i][j]!=0)||(i==j&&matrix[i][j]!=matrix[0][0]))
                    ok=0;
        if(ok)
            printf("6. Scalar Matrix\n");
    }
    // 7. Upper Triangular Matrix
    if(rows==cols){
        int ok=1;
        for(int i=0;i<rows;i++)
            for(int j=0;j<i;j++)
                if(matrix[i][j]!=0)
                    ok=0;
        if(ok)
            printf("7. Upper Triangular Matrix\n");
    }
    // 8. Lower Triangular Matrix
    if(rows==cols){
        int ok=1;
        for(int i=0;i<rows;i++)
            for(int j=i+1;j<cols;j++)
                if(matrix[i][j]!=0)
                    ok=0;
        if(ok)
            printf("8. Lower Triangular Matrix\n");
    }
    // 9. Symmetric and 10. Skew-Symmetric
    if(rows==cols){
        int sym=1,skew=1;
        for(int i=0;i<rows;i++)
            for(int j=0;j<cols;j++){
                if(matrix[i][j]!=matrix[j][i])
                    sym=0;
                if(matrix[i][j]!=-matrix[j][i])
                    skew=0;
            }
        if(sym)
            printf("9. Symmetric Matrix\n");
        if(skew)
            printf("10. Skew-Symmetric Matrix\n");
    }
    // 11. Singular / Non-Singular Matrix (1x1 to 5x5)
    if(rows==cols){
        int p[5],more=1;
        long long det=0,product;
        for(int i=0;i<rows;i++)
            p[i]=i;
        while(more){
            product=1;
            int inversions=0;
            for(int i=0;i<rows;i++){
                product*=matrix[i][p[i]];
                for(int j=i+1;j<rows;j++)
                    if(p[i]>p[j])
                        inversions++;
            }
            if(inversions%2==0)
                det+=product;
            else
                det-=product;
            int i=rows-2;
            while(i>=0&&p[i]>=p[i+1])
                i--;
            if(i<0)
                more=0;
            else{
                int j=rows-1;
                while(p[j]<=p[i])
                    j--;
                int temp=p[i];
                p[i]=p[j];
                p[j]=temp;
                int left=i+1,right=rows-1;
                while(left<right){
                    temp=p[left];
                    p[left]=p[right];
                    p[right]=temp;
                    left++;
                    right--;
                }
            }
        }
        if(det==0)
            printf("11. Singular Matrix\n");
        else
            printf("11. Non-Singular Matrix\n");
    }
    // 12. Equal Matrix
    printf("Enter second matrix:\n");
    for(int i=0;i<rows;i++)
        for(int j=0;j<cols;j++)
            scanf("%d",&matrix2[i][j]);
    int equal=1;
    for(int i=0;i<rows;i++)
        for(int j=0;j<cols;j++)
            if(matrix[i][j]!=matrix2[i][j])
                equal=0;
    if(equal)
        printf("12. Equal Matrices\n");
    else
        printf("12. Matrices are not equal\n");
    // 13. Row Matrix
    if(rows==1)
        printf("13. Row Matrix\n");
    // 14. Column Matrix
    if(cols==1)
        printf("14. Column Matrix\n");
    // 15. Null Matrix
    if(zero)
        printf("15. Null Matrix\n");
    // 16. Idempotent Matrix: A*A=A
    if(rows==cols){
        int result[5][5],ok=1;
        for(int i=0;i<rows;i++)
            for(int j=0;j<cols;j++){
                result[i][j]=0;
                for(int k=0;k<cols;k++)
                    result[i][j]+=matrix[i][k]*matrix[k][j];
            }
        for(int i=0;i<rows;i++)
            for(int j=0;j<cols;j++)
                if(result[i][j]!=matrix[i][j])
                    ok=0;
        if(ok)
            printf("16. Idempotent Matrix\n");
    }
    // 17. Nilpotent Matrix: A^k=0
    if(rows==cols){
        int power[5][5],result[5][5],ok=0;
        for(int i=0;i<rows;i++)
            for(int j=0;j<cols;j++)
                power[i][j]=matrix[i][j];
        for(int n=1;n<=rows;n++){
            int allZero=1;
            for(int i=0;i<rows;i++)
                for(int j=0;j<cols;j++)
                    if(power[i][j]!=0)
                        allZero=0;
            if(allZero){
                ok=1;
                break;
            }
            for(int i=0;i<rows;i++)
                for(int j=0;j<cols;j++){
                    result[i][j]=0;
                    for(int k=0;k<cols;k++)
                        result[i][j]+=power[i][k]*matrix[k][j];
                }
            for(int i=0;i<rows;i++)
                for(int j=0;j<cols;j++)
                    power[i][j]=result[i][j];
        }
        if(ok)
            printf("17. Nilpotent Matrix\n");
    }
    return 0;
}