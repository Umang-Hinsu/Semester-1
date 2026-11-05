#include <stdio.h>

int main()
{
    FILE *fp;
    char ch;
    char name[20];
    int age;

    fp = fopen("file.txt", "w+");

    fprintf(fp, "Rahul 20\n");
    fprintf(fp, "Hello C");

    rewind(fp);

    fscanf(fp, "%s %d", name, &age);

    printf("Name = %s\n", name);
    printf("Age = %d\n", age);

    fseek(fp, 0, SEEK_END);

    fputc('!', fp);

    rewind(fp);

    printf("\nFile Contents:\n");

    while ((ch = fgetc(fp)) != EOF)
    {
        printf("%c", ch);
    }

    fclose(fp);

    return 0;
}