#include <stdio.h>
#include <stdlib.h>

struct Student {
    int roll_no;
    char name[30];
    float marks;
};

int main() {
    FILE *fp;
    struct Student s;
    int n, i;

    printf("Name:Kartik Pramodkumar Thakkar\n");
    printf("Enrollment no:240410107057\n");
    printf("Enter number of students: ");
    scanf("%d", &n);

    fp = fopen("student.dat", "wb");
    if (fp == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    for (i = 0; i < n; i++) {
        printf("\nEnter details of student %d\n", i + 1);
        printf("Roll No: ");
        scanf("%d", &s.roll_no);

        printf("Name: ");
        scanf(" %29[^\n]", s.name);

        printf("Marks: ");
        scanf("%f", &s.marks);

        fwrite(&s, sizeof(struct Student), 1, fp);
    }

    fclose(fp);
    printf("\nRecords successfully written to binary file.\n");

    fp = fopen("student.dat", "rb");
    if (fp == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    printf("\nDisplaying Records:\n");
    printf("Roll No\tName\tMarks\n");
    printf("-------------------------\n");

    while (fread(&s, sizeof(struct Student), 1, fp) == 1) {
        printf("%d\t%s\t%.2f\n", s.roll_no, s.name, s.marks);
    }

    fclose(fp);
    return 0;
}

