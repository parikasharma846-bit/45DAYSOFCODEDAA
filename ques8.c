//8. Student Result Analysis
//• Store the roll number, name, and marks in five subjects for N students using structures.
//• Calculate the total, percentage, and grade of each student.
//• Display the class topper, students who failed in one or more subjects, and the class average.
#include <stdio.h>

struct Student {
    int roll;
    char name[50];
    int marks[5];
    int total;
    float percentage;
    char grade;
    int failed;
};

int main() {
    struct Student s[100];
    int n, i, j;
    int topper = 0;
    float classTotal = 0;

    printf("Enter number of students: ");
    scanf("%d", &n);

    // Input student details
    for (i = 0; i < n; i++) {
        printf("\nEnter details of student %d:\n", i + 1);

        printf("Roll number: ");
        scanf("%d", &s[i].roll);

        printf("Name: ");
        scanf(" %[^\n]", s[i].name);

        s[i].total = 0;
        s[i].failed = 0;

        printf("Enter marks in 5 subjects:\n");
        for (j = 0; j < 5; j++) {
            scanf("%d", &s[i].marks[j]);

            s[i].total += s[i].marks[j];

            if (s[i].marks[j] < 33)
                s[i].failed = 1;
        }

        // Calculate percentage
        s[i].percentage = s[i].total / 5.0;

        // Calculate grade
        if (s[i].failed)
            s[i].grade = 'F';
        else if (s[i].percentage >= 90)
            s[i].grade = 'A';
        else if (s[i].percentage >= 75)
            s[i].grade = 'B';
        else if (s[i].percentage >= 60)
            s[i].grade = 'C';
        else if (s[i].percentage >= 50)
            s[i].grade = 'D';
        else
            s[i].grade = 'E';

        classTotal += s[i].percentage;

        // Find topper
        if (s[i].percentage > s[topper].percentage)
            topper = i;
    }

    // Display results
    printf("\n----- STUDENT RESULTS -----\n");

    for (i = 0; i < n; i++) {
        printf("\nRoll No: %d", s[i].roll);
        printf("\nName: %s", s[i].name);
        printf("\nTotal: %d", s[i].total);
        printf("\nPercentage: %.2f%%", s[i].percentage);
        printf("\nGrade: %c\n", s[i].grade);
    }

    // Display class topper
    printf("\n----- CLASS TOPPER -----\n");
    printf("Roll No: %d\n", s[topper].roll);
    printf("Name: %s\n", s[topper].name);
    printf("Percentage: %.2f%%\n", s[topper].percentage);

    // Display failed students
    printf("\n----- STUDENTS WHO FAILED -----\n");

    for (i = 0; i < n; i++) {
        if (s[i].failed)
            printf("%d - %s\n", s[i].roll, s[i].name);
    }

    // Class average
    printf("\nClass Average: %.2f%%\n", classTotal / n);

    return 0;
}
