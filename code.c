#include <stdio.h>
#include <string.h>
// Define a structure to store student information
struct Student {
    char id[20]; // Allow for a mixed format ID
    char fullName[100];
    int age;
};
   // Function to add a new student record
void addStudent(struct Student students[], int *count) {
    if (*count < 100) {
        struct Student newStudent;
        printf("Enter student ID (alphanumeric, e.g., RA2311027010141): ");
        scanf("%s", newStudent.id);

        // Clear the input buffer
        while (getchar() != '\n');

        printf("Enter student full name: ");
        fgets(newStudent.fullName, sizeof(newStudent.fullName), stdin);
// Remove the newline character
        newStudent.fullName[strcspn(newStudent.fullName, "\n")] = '\0'; 
        printf("Enter student age: ");
        scanf("%d", &newStudent.age);

        students[*count] = newStudent;
        (*count)++;
        printf("Student record added successfully!\n");
    } else {
        printf("Student database is full.\n");
    }
}
// Function to display all student records
void displayStudents(struct Student students[], int count) {
    if (count == 0) {
        printf("No student records to display.\n");
    } else {
        printf("Student Records:\n");
        for (int i = 0; i < count; i++) {
            printf("-------------\n");
            printf("ID: %s\n", students[i].id);
            printf("Full Name: %s\n", students[i].fullName);
            printf("Age: %d\n", students[i].age);
            printf("-------------\n");
        }
    }
}

// Function to search for a student by ID
void searchStudent(struct Student students[], int count, const char searchID[]) {
    int found = 0;
    for (int i = 0; i < count; i++) {
        if (strcmp(students[i].id, searchID) == 0) {
            printf("Student Found:\n");
            printf("ID: %s\n", students[i].id);
            printf("Full Name: %s\n", students[i].fullName);
            printf("Age: %d\n", students[i].age);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Student not found with ID %s\n", searchID);
    }
}

// Function to update the student details
void updateStudent(struct Student students[],int count,const char searchID[]){
    int i,found=0;
    for (i = 0; i < count; i++) {
        if (strcmp(students[i].id, searchID) == 0) {
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Student not found with ID %s\n", searchID);
    }
    else{
    int num=0;
    printf("What parameter would you like to update:\n");
    printf("1. ID\n");
    printf("2. Full Name\n");
    printf("3. Age\n");
    printf("Enter choice: ");
    scanf("%d",&num);
    while (getchar() != '\n');
    switch (num){
        case 1:
            
            printf("Enter new ID: ");
            scanf("%s",students[i].id); 
            printf("The ID has been succesfully updated.\n");
            break;
        
        case 2:
            
            printf("Enter new Name: ");
            scanf("%s",students[i].fullName);
            printf("The Name has been succesfully updated.\n");
            break;

        case 3:
            
            printf("Enter new Age: ");
            scanf("%d",&students[i].age);
            printf("The Age has been succesfully updated.\n");
            break;
        default:
            printf("Invalid choice. Please Try again.\n");

    }
    }
    

}
int main() {
    struct Student students[100];
    int count = 0;
    int choice;
    do {
        printf("\nStudent Management System\n");
        printf("1. Add Student\n");
        printf("2. Display Students\n");
        printf("3. Search Student\n");
        printf("4. Update Student info\n");
        printf("5. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addStudent(students, &count);
                break;
            case 2:
                displayStudents(students, count);
                break;
            case 3:
                if (count == 0) {
                    printf("No student records to search.\n");
                } else {
                    char searchID[20];
                    printf("Enter student ID to search: ");
                    scanf("%s", searchID);
                    searchStudent(students, count, searchID);
                }
                break;
            
            case 4:
                if (count==0){
                    printf("No student records to update. \n");
                } else {
                    char searchID[20];
                    printf("Enter student ID to update: ");
                    scanf("%s", searchID);
                    updateStudent(students, count, searchID);
                }
                break;
            case 5:
                printf("Exiting the program. Goodbye!\n");
                break; 
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);
    return 0;
 }
