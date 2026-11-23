#include <stdio.h>
#include <stdlib.h>

// Structure type definition (no global structure variable declared)
struct Student {
    int roll_no;
    char name[50];
    int backlogs;
};

// Function prototypes
void writeStudentsToFile(const char *filename, int n);
void findHighBacklogs(const char *filename);
void modifyStudentBacklog(const char *filename, int target_roll, int new_backlog);
void displayFileContents(const char *filename);

int main() {
    const char *filename = "student.txt";
    int n, target_roll;

    // Step 1: Write student data
    printf("Enter number of students: ");
    scanf("%d", &n);
    writeStudentsToFile(filename, n);

    // Step 2: Find students with > 5 backlogs
    findHighBacklogs(filename);

    // Step 3: Modify 1 student's backlogs to 3
    printf("\nEnter Roll Number to modify backlogs to 3: ");
    scanf("%d", &target_roll);
    modifyStudentBacklog(filename, target_roll, 3);

    // Step 4: Verify updated file contents
    displayFileContents(filename);

    return 0;
}

void writeStudentsToFile(const char *filename, int n) {
    FILE *fp = fopen(filename, "w");
    struct Student s; // Local structure variable

    if (fp == NULL) {
        printf("Error opening file for writing!\n");
        exit(1);
    }

    for (int i = 0; i < n; i++) {
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
    printf("\nData stored successfully in %s.\n", filename);
}

void findHighBacklogs(const char *filename) {
    FILE *fp = fopen(filename, "r");
    struct Student s; // Local structure variable
    int found = 0;

    if (fp == NULL) {
        printf("Error opening file for reading!\n");
        return;
    }

    printf("\nStudents with more than 5 backlogs:\n");
    while (fscanf(fp, "%d %s %d", &s.roll_no, s.name, &s.backlogs) != EOF) {
        if (s.backlogs > 5) {
            printf("Roll No: %d (Name: %s, Backlogs: %d)\n", s.roll_no, s.name, s.backlogs);
            found = 1;
        }
    }

    if (!found) {
        printf("None found.\n");
    }
    fclose(fp);
}

void modifyStudentBacklog(const char *filename, int target_roll, int new_backlog) {
    FILE *fp = fopen(filename, "r");
    struct Student list[100]; // Local structure array
    int count = 0, modified = 0;

    if (fp == NULL) {
        printf("Error opening file for reading!\n");
        return;
    }

    while (fscanf(fp, "%d %s %d", &list[count].roll_no, list[count].name, &list[count].backlogs) != EOF) {
        if (list[count].roll_no == target_roll) {
            list[count].backlogs = new_backlog;
            modified = 1;
        }
        count++;
    }
    fclose(fp);

    if (!modified) {
        printf("Roll Number %d not found. No changes made.\n", target_roll);
        return;
    }

    fp = fopen(filename, "w");
    if (fp == NULL) {
        printf("Error opening file for writing!\n");
        return;
    }

    for (int i = 0; i < count; i++) {
        fprintf(fp, "%d %s %d\n", list[i].roll_no, list[i].name, list[i].backlogs);
    }
    fclose(fp);
    printf("Backlogs for Roll No %d updated to %d.\n", target_roll, new_backlog);
}

void displayFileContents(const char *filename) {
    FILE *fp = fopen(filename, "r");
    struct Student s; // Local structure variable

    if (fp == NULL) {
        printf("Error opening file for verification!\n");
        return;
    }

    printf("\n--- Verified Data in %s ---\n", filename);
    printf("Roll No\tName\t\tBacklogs\n");
    printf("------------------------------------\n");
    while (fscanf(fp, "%d %s %d", &s.roll_no, s.name, &s.backlogs) != EOF) {
        printf("%d\t%-15s\t%d\n", s.roll_no, s.name, s.backlogs);
    }
    fclose(fp);
}
