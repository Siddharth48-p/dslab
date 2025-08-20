/*Write a C program to define a student structure with the data members to store name,
roll no and grade of the student. Also write the required functions to read, display, and
sort student information according to the roll number of the student. All the member
functions will have array of objects as arguments.*/
/*#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 100
#define NAME_LENGTH 50

// Define the student structure
typedef struct {
    char name[NAME_LENGTH];
    int roll_no;
    char grade;
} student;

// Function prototypes
void readStudents(student arr[], int n);
void displayStudents(const student arr[], int n);
void sortStudentsByRollNo(student arr[], int n);

int main() {
    int n;

    printf("Enter number of students: ");
    scanf("%d", &n);

    student students[MAX_STUDENTS];

    // Read student data
    readStudents(students, n);

    // Sort students by roll number
    sortStudentsByRollNo(students, n);

    // Display sorted student data
    printf("\nSorted Student List by Roll Number:\n");
    displayStudents(students, n);

    return 0;
}

// Function to read student information
void readStudents(student arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("\nEnter details for student %d\n", i + 1);

        printf("Name: ");
        // Read string with spaces
        getchar();  // Clear newline character from buffer
        fgets(arr[i].name, NAME_LENGTH, stdin);
        // Remove trailing newline character if any
        arr[i].name[strcspn(arr[i].name, "\n")] = '\0';

        printf("Roll No: ");
        scanf("%d", &arr[i].roll_no);

        printf("Grade: ");
        getchar();  // Clear newline character before reading char
        scanf("%c", &arr[i].grade);
    }
}

// Function to display student information
void displayStudents(const student arr[], int n) {
    printf("%-20s %-10s %-6s\n", "Name", "Roll No", "Grade");
    printf("----------------------------------------\n");
    for (int i = 0; i < n; i++) {
        printf("%-20s %-10d %-6c\n", arr[i].name, arr[i].roll_no, arr[i].grade);
    }
}

// Function to sort students by roll number using Bubble Sort
void sortStudentsByRollNo(student arr[], int n) {
    student temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j].roll_no > arr[j + 1].roll_no) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}*/

