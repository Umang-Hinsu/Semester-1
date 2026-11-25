#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *a, n, i, sum = 0;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    a = (int*)malloc(n * sizeof(int));

    if (a == NULL)
    {
        printf("Memory allocation failed.");
        return 1;
    }

    printf("Enter %d numbers:\n", n);

    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
        sum = sum + a[i];
    }

    printf("Sum = %d", sum);

    free(a);

    return 0;
}
