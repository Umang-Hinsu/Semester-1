#include <stdio.h>
#include <stdlib.h>

struct Student {
    int roll_no;
    char name[50];
    int backlogs;
};

int main() {
    FILE *fp;
    struct Student s[100];
    int count = 0, i, target_roll, modified = 0;

    // 1. Read existing records from student.txt into structure array
    fp = fopen("student.txt", "r");
    if (fp == NULL) {
        printf("Error opening file! Run Part A first to create student.txt.\n");
        return 1;
    }

    while (fscanf(fp, "%d %s %d", &s[count].roll_no, s[count].name, &s[count].backlogs) != EOF) {
        count++;
    }
    fclose(fp);

    // 2. Modify the backlogs of a specific student to 3
    printf("Enter the Roll Number of the student whose backlogs you want to change to 3: ");
    scanf("%d", &target_roll);

    for (i = 0; i < count; i++) {
        if (s[i].roll_no == target_roll) {
            s[i].backlogs = 3;
            modified = 1;
            break;
        }
    }

    if (!modified) {
        printf("Student with Roll Number %d not found.\n", target_roll);
        return 0;
    }

    // 3. Store the updated data back into student.txt
    fp = fopen("student.txt", "w");
    if (fp == NULL) {
        printf("Error opening file for writing!\n");
        return 1;
    }

    for (i = 0; i < count; i++) {
        fprintf(fp, "%d %s %d\n", s[i].roll_no, s[i].name, s[i].backlogs);
    }
    fclose(fp);
    printf("\nRecord updated successfully.\n");

    // 4. Verify data by reading from file and printing to console
    fp = fopen("student.txt", "r");
    struct Student temp;
    printf("\n--- Verified Data in student.txt ---\n");
    printf("Roll No\tName\t\tBacklogs\n");
    printf("------------------------------------\n");
    while (fscanf(fp, "%d %s %d", &temp.roll_no, temp.name, &temp.backlogs) != EOF) {
        printf("%d\t%-15s\t%d\n", temp.roll_no, temp.name, temp.backlogs);
    }
    fclose(fp);

    return 0;
}
