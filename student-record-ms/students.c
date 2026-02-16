#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct student {
    int id;
    char name[50];
    float marks;
};

struct student s[100];
int count = 0;

// LOGIN SYSTEM
void login() {
    char user[20], pass[20];

    printf("\n===== LOGIN SYSTEM =====\n");
    printf("Username: ");
    scanf("%s", user);
    printf("Password: ");
    scanf("%s", pass);

    if(strcmp(user, "admin") == 0 && strcmp(pass, "1234") == 0) {
        printf("\nLogin Successful!\n");
    } else {
        printf("\nWrong Username or Password!\n");
        exit(0);
    }
}

// SAVE TO FILE
void saveToFile() {
    FILE *fp;
    int i;

    fp = fopen("students.txt", "w");
    for(i = 0; i < count; i++) {
        fprintf(fp, "%d %s %f\n", s[i].id, s[i].name, s[i].marks);
    }
    fclose(fp);
}

// LOAD FROM FILE
void loadFromFile() {
    FILE *fp;
    fp = fopen("students.txt", "r");
    if(fp == NULL) return;

    while(fscanf(fp, "%d %s %f", &s[count].id, s[count].name, &s[count].marks) != EOF) {
        count++;
    }
    fclose(fp);
}

// ADD STUDENT
void addStudent() {
    printf("\nEnter ID: ");
    scanf("%d", &s[count].id);

    printf("Enter Name: ");
    scanf(" %s", s[count].name);

    printf("Enter Marks: ");
    scanf("%f", &s[count].marks);

    count++;
    saveToFile();
    printf("Student Added & Saved!\n");
}

// DISPLAY STUDENTS
void viewStudents() {
    int i;
    for(i = 0; i < count; i++) {
        printf("\nID: %d  Name: %s  Marks: %.2f", s[i].id, s[i].name, s[i].marks);
    }
}

// SEARCH STUDENT
void searchStudent() {
    int id, i;
    printf("\nEnter ID to search: ");
    scanf("%d", &id);

    for(i = 0; i < count; i++) {
        if(s[i].id == id) {
            printf("\nFound: %d %s %.2f", s[i].id, s[i].name, s[i].marks);
            return;
        }
    }
    printf("\nStudent Not Found!");
}

// UPDATE STUDENT
void updateStudent() {
    int id, i;
    printf("\nEnter ID to update: ");
    scanf("%d", &id);

    for(i = 0; i < count; i++) {
        if(s[i].id == id) {
            printf("Enter New Name: ");
            scanf(" %s", s[i].name);
            printf("Enter New Marks: ");
            scanf("%f", &s[i].marks);
            saveToFile();
            printf("Updated Successfully!");
            return;
        }
    }
    printf("\nStudent Not Found!");
}

// DELETE STUDENT
void deleteStudent() {
    int id, i, j;
    printf("\nEnter ID to delete: ");
    scanf("%d", &id);

    for(i = 0; i < count; i++) {
        if(s[i].id == id) {
            for(j = i; j < count-1; j++) {
                s[j] = s[j+1];
            }
            count--;
            saveToFile();
            printf("Deleted Successfully!");
            return;
        }
    }
    printf("\nStudent Not Found!");
}

// SORT BY MARKS
void sortByMarks() {
    struct student temp;
    int i, j;

    for(i = 0; i < count; i++) {
        for(j = i+1; j < count; j++) {
            if(s[i].marks < s[j].marks) {
                temp = s[i];
                s[i] = s[j];
                s[j] = temp;
            }
        }
    }
    printf("\nSorted by Marks!");
}

// SORT BY NAME
void sortByName() {
    struct student temp;
    int i, j;

    for(i = 0; i < count; i++) {
        for(j = i+1; j < count; j++) {
            if(strcmp(s[i].name, s[j].name) > 0) {
                temp = s[i];
                s[i] = s[j];
                s[j] = temp;
            }
        }
    }
    printf("\nSorted by Name!");
}

// TOTAL & AVERAGE
void totalAverage() {
    float total = 0;
    int i;

    for(i = 0; i < count; i++) {
        total += s[i].marks;
    }
    printf("\nTotal Marks = %.2f", total);
    printf("\nAverage Marks = %.2f", total / count);
}

// GRADE SYSTEM
void gradeStudent() {
    int i;
    for(i = 0; i < count; i++) {
        printf("\n%s -> ", s[i].name);
        if(s[i].marks >= 90) printf("Grade A");
        else if(s[i].marks >= 75) printf("Grade B");
        else if(s[i].marks >= 60) printf("Grade C");
        else printf("Fail");
    }
}

// MAIN FUNCTION
int main() {
    int ch;

    login();
    loadFromFile();

    while(1) {
        printf("\n\n===== STUDENT MANAGEMENT SYSTEM =====");
        printf("\n1.Add Student");
        printf("\n2.View Students");
        printf("\n3.Search Student");
        printf("\n4.Update Student");
        printf("\n5.Delete Student");
        printf("\n6.Sort by Marks");
        printf("\n7.Sort by Name");
        printf("\n8.Total & Average Marks");
        printf("\n9.Grade Students");
        printf("\n10.Exit");
        printf("\nEnter choice: ");
        scanf("%d", &ch);

        switch(ch) {
            case 1: addStudent(); break;
            case 2: viewStudents(); break;
            case 3: searchStudent(); break;
            case 4: updateStudent(); break;
            case 5: deleteStudent(); break;
            case 6: sortByMarks(); break;
            case 7: sortByName(); break;
            case 8: totalAverage(); break;
            case 9: gradeStudent(); break;
            case 10: return 0;
            default: printf("Wrong Choice!");
        }
    }
}

