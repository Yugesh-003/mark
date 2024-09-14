#include <stdio.h>
#include <stdlib.h>

typedef struct student {
    int rno;
    char sname[40];
    int m1, m2, m3;
    int total;
    float per;
} student;

void store() {
    FILE *fp;
    student s1;
    fp = fopen("stud2.txt", "a+");

    printf("Enter roll no  :  ");
    scanf("%d", &s1.rno);
    getchar(); // Consume leftover newline
    printf("Enter name     :  ");
    fgets(s1.sname, sizeof(s1.sname), stdin);
    printf("Enter 3 subject marks   :  ");
    scanf("%d %d %d", &s1.m1, &s1.m2, &s1.m3);
    
    s1.total = s1.m1 + s1.m2 + s1.m3;
    s1.per = s1.total / 3.0;

    fwrite(&s1, sizeof(student), 1, fp);

    fclose(fp);
}

void display() {
    FILE *fp;
    student s1;
    fp = fopen("stud2.txt", "r");
    if (fp == NULL) {
        printf("Cannot open file.\n");
        return;
    }

    printf("\nRoll No    Name               Total     Percentage   \n");
    while (fread(&s1, sizeof(student), 1, fp)) 
    {
        printf("%d\t%-15s\t%d\t%.2f\n", s1.rno, s1.sname, s1.total, s1.per);
    }
    fclose(fp);
}

int main() {
    int ch;

    do {
        printf("1. Store the student data\n");
        printf("2. Retrieve the student data\n");
        printf("0. Exit\n");
        printf("Enter your choice  :  ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                store();
                break;
            case 2:
                display();
                break;
            case 0:
                exit(0);
                break;
            default:
                printf("Wrong choice\n");
                break;
        }
    } while (ch != 0);

    return 0;
}
