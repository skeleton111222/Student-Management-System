#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Structure declaration*/
struct Student {
    int id;
    char name[50];
    int age;
    float marks;
};

/* Function declarations */
void addStudent();
void viewStudents();
void updateStudent();
void deleteStudent();

/* Main function */
int main() {
    int choice;

    while (1) {
	/* Menu */
        printf("\n===== Student Management System =====\n");
        printf("1. Add Student\n");
        printf("2. View All Students\n");
        printf("3. Update Student\n");
        printf("4. Delete Student\n");
        printf("5. Exit\n");
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
                updateStudent();
                break;
            case 4:
                deleteStudent();
                break;
            case 5:
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}

/* Add student record */
void addStudent() {
    struct Student s;
    FILE *fp = fopen("student.txt", "ab");

    if (fp == NULL) {
        printf("Error opening file!\n");
        return;
    }

    printf("Enter Student ID: ");
    scanf("%d", &s.id);
    printf("Enter Name: ");
    scanf(" %[^\n]", s.name);
    printf("Enter Age: ");
    scanf("%d", &s.age);
    printf("Enter Marks: ");
    scanf("%f", &s.marks);

    fwrite(&s, sizeof(s), 1, fp);
    fclose(fp);

    printf("Student record added successfully!\n");
}

/* View all students */
void viewStudents() {
    struct Student s;
    FILE *fp = fopen("student.txt", "rb");

    if (fp == NULL) {
        printf("No records found!\n");
        return;
    }

    printf("\nID\tName\t\tAge\tMarks\n");
    printf("----------------------------------------\n");

    while (fread(&s, sizeof(s), 1, fp)) {
        printf("%d\t%s\t\t%d\t%.2f\n",
               s.id, s.name, s.age, s.marks);
    }

    fclose(fp);
}

/* Update student record */
void updateStudent() {
    struct Student s;
    FILE *fp = fopen("student.txt", "rb+");
    int id, found = 0;

    if (fp == NULL) {
        printf("File not found!\n");
        return;
    }

    printf("Enter Student ID to update: ");
    scanf("%d", &id);

    while (fread(&s, sizeof(s), 1, fp)) {
        if (s.id == id) {
            printf("Enter New Name: ");
            scanf(" %[^\n]", s.name);
            printf("Enter New Age: ");
            scanf("%d", &s.age);
            printf("Enter New Marks: ");
            scanf("%f", &s.marks);

            fseek(fp, -sizeof(s), SEEK_CUR);
            fwrite(&s, sizeof(s), 1, fp);
            found = 1;
            break;
        }
    }

    fclose(fp);

    if (found)
        printf("Student record updated successfully!\n");
    else
        printf("Student not found!\n");
}

/* Delete student record */
void deleteStudent() {
    struct Student s;
    FILE *fp = fopen("student.txt", "rb");
    FILE *temp = fopen("temp.txt", "wb");
    int id, found = 0;

    if (fp == NULL) {
        printf("File not found!\n");
        return;
    }

    printf("Enter Student ID to delete: ");
    scanf("%d", &id);

    while (fread(&s, sizeof(s), 1, fp)) {
        if (s.id != id) {
            fwrite(&s, sizeof(s), 1, temp);
        } else {
            found = 1;
        }
    }

    fclose(fp);
    fclose(temp);

    remove("student.txt");
    rename("temp.txt", "student.txt");

    if (found)
        printf("Student record deleted successfully!\n");
    else
        printf("Student not found!\n");
}
