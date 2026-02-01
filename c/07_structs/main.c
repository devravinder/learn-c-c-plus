#include <stdio.h>

struct Student {
    char name[20];
    int age;
    double gpa;
    char section;
};

int main() {

    // create first student
    struct Student s1 = {"Rahul", 20, 8.5, 'A'};

    // create second student
    struct Student s2 = {"Priya", 19, 9.1, 'B'};

    // print student 1
    printf("Student 1\n");
    printf("Name: %s\n", s1.name);
    printf("Age: %d\n", s1.age);
    printf("GPA: %.2lf\n", s1.gpa);
    printf("Section: %c\n\n", s1.section);

    // print student 2
    printf("Student 2\n");
    printf("Name: %s\n", s2.name);
    printf("Age: %d\n", s2.age);
    printf("GPA: %.2lf\n", s2.gpa);
    printf("Section: %c\n", s2.section);

    printf("========================\n");

    struct Student s3;

    // s3.name = "Ravinder"; // error, name is string
    strcpy(s3.name, "Ravinder");

    s3.age = 28;
    s3.gpa = 4.5;
    s3.section = 'A';

    printf("Student 3\n");
    printf("Name: %s\n", s3.name);
    printf("Age: %d\n", s3.age);
    printf("GPA: %.2lf\n", s3.gpa);
    printf("Section: %c\n", s3.section);


    return 0;
}
