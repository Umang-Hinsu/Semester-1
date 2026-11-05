#include <stdio.h>

int main()
{
    FILE *fp;

    fp = fopen("file.txt", "w");

    if (fp == NULL)
    {
        printf("File cannot be created");
        return 1;
    }

    printf("File created and opened successfully");

    fclose(fp);

    printf("\nFile closed successfully");

    return 0;
}