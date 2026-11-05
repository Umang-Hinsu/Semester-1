#include <stdio.h>

int main()
{
    FILE *fp1, *fp2;
    char ch;

    fp1 = fopen("file1.txt", "a");
    fp2 = fopen("file2.txt", "r");

    if (fp1 == NULL || fp2 == NULL)
    {
        printf("File not found");
        return 1;
    }

    while ((ch = fgetc(fp2)) != EOF)
    {
        fputc(ch, fp1);
    }

    printf("File appended successfully");

    fclose(fp1);
    fclose(fp2);

    return 0;
}