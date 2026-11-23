#include <stdio.h>
#include <stdlib.h>

struct Student {
    int roll_no;
    char name[50];
    int backlogs;
};

int main() {
    FILE *fp;
    struct Student s;
    int n, i;

    printf("Enter number of students: ");
    scanf("%d", &n);

    // 1. Open file in write mode and store data
    fp = fopen("student.txt", "w");
    if (fp == NULL) {
        printf("Error opening file for writing!\n");
        return 1;
    }

    for (i = 0; i < n; i++) {
        printf("\nEnter details for Student %d:\n", i + 1);
        printf("Roll Number: ");
        scanf("%d", &s.roll_no);
        printf("Name (single word): ");
        scanf("%s", s.name);
        printf("Backlogs: ");
        scanf("%d", &s.backlogs);

        fprintf(fp, "%d %s %d\n", s.roll_no, s.name, s.backlogs);
    }
    fclose(fp);
    printf("\nData successfully written to student.txt.\n");

    // 2. Open file in read mode and find students with > 5 backlogs
    fp = fopen("student.txt", "r");
    if (fp == NULL) {
        printf("Error opening file for reading!\n");
        return 1;
    }

    printf("\nRoll numbers of students with more than 5 backlogs:\n");
    int found = 0;
    while (fscanf(fp, "%d %s %d", &s.roll_no, s.name, &s.backlogs) != EOF) {
        if (s.backlogs > 5) {
            printf("Roll No: %d (Name: %s, Backlogs: %d)\n", s.roll_no, s.name, s.backlogs);
            found = 1;
        }
    }

    if (!found) {
        printf("No student has more than 5 backlogs.\n");
    }

    fclose(fp);
    return 0;
}
