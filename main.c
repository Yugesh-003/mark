//main.c
#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include"percentage.h"
#include"details.h"

void input()
{   
    FILE *file;
    struct details d;

    subjects_assign(&d);

    file = fopen("student1.txt","w+"); 
    if (file == NULL)
    {
        printf("Error opening file");
    }

    d.total = 0.0;
    for(int i = 0; i < 8; i++)
    { 
        printf("\nEnter the marks for %s\n", d.subjects[i]);
        if(i<6)
        {
           printf("Viva mark: ");
           scanf("%d", &d.viva[i]);
        }
        printf("Exam mark: ");
        scanf("%d", &d.exam[i]);

        printf("Attendance percentage: ");
        scanf("%d", &d.aper[i]);

        printf("Assignment mark: ");
        scanf("%d", &d.assignmentmark[i]);

        printf("I internal mark: ");
        scanf("%f", &d.internal1[i]);

        printf("II internal: ");
        scanf("%f", &d.internal2[i]);
    } 

    fwrite(&d, sizeof(d),1,file);

    fclose(file);
} 

void calculation()
{
    FILE *file;
    struct details d;
    file = fopen("student1.txt","a+");
    if (file == NULL)
    {
        printf("Error opening file");
        return;
    }
    d.total = 0.0;
    for (int i = 0; i < 8; i++)
    {
        if (i < 6)
        {
            d.amark[i]=att_percent(d.aper[i],5,0.5);  
            d.internal[i] = (d.internal1[i] + d.internal2[i]) / 6.66666;
            d.theory[i] = (d.viva[i] + d.exam[i]) / 1.333333;
        }
        else
        {
            d.amark[i]=att_percent(d.aper[i],10,1);
            d.internal[i] = (d.internal1[i] + d.internal2[i]) / 5.0;
        }
        if(i<6)
        {
            d.stotal[i] = d.internal[i] + d.amark[i] + d.assignmentmark[i] + d.theory[i];
        }    
        else
        {
            d.stotal[i] = d.internal[i] + d.amark[i] + d.assignmentmark[i] + d.exam[i]; 

        }
        d.total += d.stotal[i]; 

    }
    fwrite(&d,sizeof(d),1,file);
    fclose(file);
}

void display() 
{
    FILE *file;
    struct details d;
    subjects_assign(&d);
    file = fopen("student1.txt", "r");
    

    if (file == NULL) 
    {
        printf("Error opening file\n");
        return ;
    }
    fread(&d, sizeof(d), 1, file);
    while(fread(&d, sizeof(d), 1, file))
    {
        for (int i = 0; i < 8; i++)  
        {
         printf("\n%s  -   %.2f\n", d.subjects[i],d.stotal[i]);
        }
    }
    
    printf("\nTotal: %.2f\n", d.total);

    fclose(file);
}

int main()
{
    int choice;
    while (1) 
    {
        printf("1. Store the student data\n");
        printf("2. Retrieve the student data\n");
        printf("0. Exit\n");
        printf("Enter your choice  :  ");
        scanf("%d", &choice);

        if (choice == 0)
         {
            printf("Exiting...\n");
            break;  
        }

        switch(choice) 
        {
            case 1:
                input();
                calculation();
                break;
            case 2:
                display();
                break;
            default:
                printf("Invalid choice, please try again.\n");
        }
    }
    return 0;
}