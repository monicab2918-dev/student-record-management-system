#include<stdio.h>

struct student {
    int id;
    char name[50];
    float marks;
};

struct student s[50];
int count = 0;

void addStudent() {
    printf("\nEnter Student ID: ");
    scanf("%d", &s[count].id);

    printf("Enter Student Name: ");
    scanf("%s", s[count].name);

    printf("Enter Marks: ");
    scanf("%f", &s[count].marks);

    count++;
    printf("Student Added Successfully!\n");
}

void viewStudents() {
    if (count == 0) {
        printf("\nNo Records Found!\n");
        return;
    }

    printf("\n--- Student Records ---\n");
    for (int i = 0; i < count; i++) {
        printf("\nID: %d", s[i].id);
        printf("\nName: %s", s[i].name);
        printf("\nMarks: %.2f\n", s[i].marks);
    }
}

int main() {
    int choice;

    while (1) {
        printf("\n===== Student Record Management System =====\n");
        printf("1. Add Student\n");
        printf("2. View Students\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStudent();
                break;
            case 2:
                viewStudents();
                break;
            case 3:
                printf("Exiting Program...");
                return 0;
            default:
                printf("Invalid Choice!");
        }
    }
}
