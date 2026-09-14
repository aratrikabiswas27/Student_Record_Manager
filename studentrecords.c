#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    int roll;
    char name[50];
    float marks;
    struct Student *next;
};

// Display all students
void display(struct Student *head) {

    struct Student *temp = head;

    if (head == NULL) {
        printf("\nNo student records available.\n");
        return;
    }

    printf("\n===== STUDENT RECORDS =====\n");

    while (temp != NULL) {

        printf("\nRoll: %d", temp->roll);
        printf("\nName: %s", temp->name);
        printf("\nMarks: %.2f\n", temp->marks);

        temp = temp->next;
    }
}

// Search student
void search(struct Student *head) {

    int searchRoll;
    int found = 0;

    struct Student *temp = head;

    printf("\nEnter roll number to search: ");
    scanf("%d", &searchRoll);

    while (temp != NULL) {

        if (temp->roll == searchRoll) {

            printf("\nStudent Found!");
            printf("\nRoll: %d", temp->roll);
            printf("\nName: %s", temp->name);
            printf("\nMarks: %.2f\n", temp->marks);

            found = 1;
            break;
        }

        temp = temp->next;
    }

    if (found == 0) {
        printf("\nStudent not found.\n");
    }
}

// Insert student at beginning
void insert(struct Student **head) {

    struct Student *newNode;

    int roll;
    char name[50];
    float marks;

    newNode = malloc(sizeof(struct Student));

    printf("\nEnter details of student:\n");

    printf("Roll: ");
    scanf("%d", &roll);

    printf("Name: ");
    scanf("%s", name);

    printf("Marks: ");
    scanf("%f", &marks);

    newNode->roll = roll;
    strcpy(newNode->name, name);
    newNode->marks = marks;

    newNode->next = *head;
    *head = newNode;

    printf("\nStudent inserted successfully!\n");
}

// Delete student
void deleteStudent(struct Student **head) {

    int deleteRoll;

    struct Student *temp = *head;
    struct Student *prev = NULL;

    printf("\nEnter roll number of student to delete: ");
    scanf("%d", &deleteRoll);

    while (temp != NULL && temp->roll != deleteRoll) {

        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {

        printf("\nStudent not found.\n");
    }
    else {

        if (prev == NULL) {
            *head = temp->next;
        }
        else {
            prev->next = temp->next;
        }

        free(temp);

        printf("\nStudent deleted successfully!\n");
    }
}

void updateStudent(struct Student *head) {

    int roll;
    struct Student *temp = head;

    printf("\nEnter roll number of student to update: ");
    scanf("%d", &roll);

    while (temp != NULL) {

        if (temp->roll == roll) {

            printf("\nEnter new details:\n");

            printf("New name: ");
            scanf("%s", temp->name);

            printf("New marks: ");
            scanf("%f", &temp->marks);

            printf("\nStudent details updated successfully!\n");
            return;
        }

        temp = temp->next;
    }

    printf("\nStudent not found.\n");
}

void findTopper(struct Student *head) {

    struct Student *temp = head;
    struct Student *topper;

    if (head == NULL) {
        printf("\nNo student records available.\n");
        return;
    }

    topper = head;

    while (temp != NULL) {

        if (temp->marks > topper->marks) {
            topper = temp;
        }

        temp = temp->next;
    }

    printf("\n===== TOPPER =====\n");
    printf("Roll: %d\n", topper->roll);
    printf("Name: %s\n", topper->name);
    printf("Marks: %.2f\n", topper->marks);
}

void calculateAverage(struct Student *head) {

    struct Student *temp = head;
    int count = 0;
    float total = 0;

    if (head == NULL) {
        printf("\nNo student records available.\n");
        return;
    }

    while (temp != NULL) {

        total = total + temp->marks;
        count++;

        temp = temp->next;
    }

    printf("\nAverage Marks: %.2f\n", total / count);
}

int main() {

    int n, i;

    struct Student *head = NULL;
    struct Student *newNode;
    struct Student *temp;

    printf("Enter number of students: ");
    scanf("%d", &n);

    // Creating n students
    for (i = 0; i < n; i++) {

        newNode = malloc(sizeof(struct Student));

        printf("\nEnter details of Student %d:\n", i + 1);

        printf("Roll: ");
        scanf("%d", &newNode->roll);

        printf("Name: ");
        scanf("%s", newNode->name);

        printf("Marks: ");
        scanf("%f", &newNode->marks);

        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
        }
        else {

            temp = head;

            while (temp->next != NULL) {
                temp = temp->next;
            }

            temp->next = newNode;
        }
    }

    // Menu
    int choice;

    do {

        printf("\n\n===== STUDENT RECORD MANAGER =====\n");
        printf("1. Display Students\n");
        printf("2. Search Student\n");
        printf("3. Insert Student\n");
        printf("4. Delete Student\n");
        printf("5. Update Student\n");
        printf("6. Find Topper\n");
        printf("7. Calculate average marks\n");
        printf("8. Exit\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:
                display(head);
                break;

            case 2:
                search(head);
                break;

            case 3:
                insert(&head);
                break;

            case 4:
                deleteStudent(&head);
                break;

            case 5:
                updateStudent(head);
                break;

            case 6:
                findTopper(head);
                break;

            case 7:
                calculateAverage(head);
                break;

            case 8:
                printf("\nExiting program\n");    

            default:
                printf("\nInvalid choice.\n");
        }

    } while (choice != 8);

    while (head != NULL) {
    temp = head;
    head = head->next;
    free(temp);
}

    return 0;
}