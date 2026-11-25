#include <stdio.h>
#include <stdlib.h>

struct student
{
    int rollno;
    char name[50];
    float marks;
};

int main()
{
    struct student *s;

    s = (struct student*)malloc(sizeof(struct student));

    if (s == NULL)
    {
        printf("Memory allocation failed.");
        return 1;
    }

    printf("Enter roll number: ");
    scanf("%d", &s->rollno);

    printf("Enter name: ");
    scanf("%49s", s->name);

    printf("Enter marks: ");
    scanf("%f", &s->marks);

    printf("\nStudent Details\n");
    printf("Roll Number = %d\n", s->rollno);
    printf("Name = %s\n", s->name);
    printf("Marks = %.2f\n", s->marks);

    free(s);

    return 0;
}
