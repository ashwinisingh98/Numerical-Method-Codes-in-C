//Program to calculate Standard Deviation of given set of numbers
#include <math.h>
#include <stdio.h>

float calculateSD(float data[],int N);

int main() {
    int i,n;
    printf("\nEnter number of elements: ");
    scanf("%d",&n);
    float data[n];
    printf("\nEnter %d elements:\n",n);

    for (i = 0; i < n; ++i)
        scanf("%f", &data[i]);
    printf("\nStandard Deviation = %.6f\n", calculateSD(data,n));
    printf("\n=======================================\n");
    return 0;
}

float calculateSD(float data[],int N) {
    float sum = 0.0, mean, SD = 0.0;
    int i;
    for (i = 0; i < N; ++i) {
        sum += data[i];
    }
    mean = sum / (float)N;
    for (i = 0; i < N; ++i)
        SD += pow(data[i] - mean, 2);
    return sqrt(SD / (float)N);
}
