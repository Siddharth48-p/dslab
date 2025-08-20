/*Define a structure Student with the following members:
char name [50] – to store student name as a string
int roll_no – to store roll number
float marks – to store marks
Write a C program that:
i. Reads the details of ‘n’ students using a function that uses pointer to structure
as an argument.
ii. Displays the details of all students using a separate function.
iii. Finds and displays the student with the highest marks using pointer-based
access.*/
#include <stdio.h>

// Define the structure
struct Student {
    char name[50];
    int roll_no;
    float marks;
};

// Function to read student details
void readStudents(struct Student *s, int n) {
    for (int i = 0; i < n; i++) {
        printf("Enter details for Student %d:\n", i + 1);
        printf("Name: ");
        scanf(" %[^\n]", s[i].name); // Read string with spaces
        printf("Roll Number: ");
        scanf("%d", &s[i].roll_no);
        printf("Marks: ");
        scanf("%f", &s[i].marks);
    }
}

// Function to display student details
void displayStudents(struct Student *s, int n) {
    printf("\nStudent Details:\n");
    for (int i = 0; i < n; i++) {
        printf("Student %d:\n", i + 1);
        printf("Name: %s\n", s[i].name);
        printf("Roll Number: %d\n", s[i].roll_no);
        printf("Marks: %.2f\n", s[i].marks);
    }
}

// Function to find and display student with highest marks
void findTopper(struct Student *s, int n) {
    struct Student *topper = s; // Start with first student

    for (int i = 1; i < n; i++) {
        if ((s + i)->marks > topper->marks) {
            topper = (s + i); // Pointer-based access
        }
    }

    printf("\nStudent with Highest Marks:\n");
    printf("Name: %s\n", topper->name);
    printf("Roll Number: %d\n", topper->roll_no);
    printf("Marks: %.2f\n", topper->marks);
}

// Main function
int main() {
    int n;

    printf("Enter number of students: ");
    scanf("%d", &n);

    // Declare array of Students
    struct Student students[n];

    // Read, display, and find topper
    readStudents(students, n);
    displayStudents(students, n);
    findTopper(students, n);

    return 0;
}

