// produce largest and smallest of the entered input numbers
#include <stdio.h>
int main()
{
    int arr[20];
    int n, i, j;
    printf("enter the total number of inputs:\n");
    scanf("%d", &n);
    
    // storing inputs in array
    printf("enter the values\n");
    for (i = 0; i < n; i++)
    {
        printf("value of arr[%d]:\t", i);
        scanf("%d", &arr[i]);
    }

    // sorting array in ascending order
    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (arr[i] > arr[j])
            {
                int temp = 0;
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    printf("\nthe largest of all is:\t %d\n", arr[n - 1]);
    printf("the smallest of all is:\t %d\n", arr[0]);
    return 0;
}
