// program to enter A and B matrix and give C = A + B as output
#include<stdio.h>
int main()
{
    int n, m, i, j;
    int A[10][10]; 
    int B[10][10];
    int C[10][10];
    printf("Enter the no. of rows you want:\n");
    scanf("%d",&n);
    printf("enter number of columns you want:\n");
    scanf("%d",&m);
    printf("Enter elements for the matrix\n");
    // storing elements in matrix A
    for(i=0; i<n; i++)
    {
        for(j=0; j<m; j++)
        {
            printf("value of a[%d][%d] element:",i,j);
            scanf("%d",&A[i][j]);
        }
    }
    // storing elements in matrix B
    for(i=0; i<n; i++)
    {
        for(j=0; j<m; j++)
        {
            printf("value of b[%d][%d] element:",i,j);
            scanf("%d",&B[i][j]);
        }
    }
    // computing elements of matrix C
    for(i=0; i<n; i++)
    {
        for(j=0; j<m; j++)
        {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
    // printing matrix A
    printf("Matrix A is:\n");
    for(i=0; i<n; i++)
    {
        for(j=0; j<m; j++)
        {
            printf("%d\t",A[i][j]);
        }
        printf("\n");
    }
    // printing matrix B
    printf("\n");
    printf("Matrix B is:\n");
    for(i=0; i<n; i++)
    {
        for(j=0; j<m; j++)
        {
            printf("%d\t",B[i][j]);
        }
        printf("\n");
    }
    // printing matrix C
    printf("*****************************************\n");
    printf("Matrix C is:\n");
    for(i=0; i<n; i++)
    {
        for(j=0; j<m; j++)
        {
            printf("%d\t",C[i][j]);
        }
        printf("\n");
    }
    return 0;
}