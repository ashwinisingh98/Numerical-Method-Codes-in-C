#include <stdio.h>
void array_reverse(int arr[])
{
    int temp;
    for (int i = 0; i < 5 / 2; i++)
    {
        temp = arr[i];
        arr[i] = arr[4 - i];
        arr[4 - i] = temp;
    }
    printf("after reversing the array:\n");
    for (int j = 0; j < 5; j++)
    {
        printf(" element %d of reversed array is %d\n", j, arr[j]);
    }
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    printf("array before reversed:\n");
    for (int j = 0; j < 5; j++)
    {
        printf(" element %d is %d\n", j, arr[j]);
    }
    array_reverse(arr);
}