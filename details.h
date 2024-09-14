typedef struct details
{
     int aper[8], viva[6], exam[8], theory[8], assignmentmark[8];
            //aper=attendance percentage
    char subjects[8][16];
            // amark = attendance mark, stotal = subject total
    float amark[8], stotal[8], internal[8], internal1[8], internal2[8], total;
    //struct student;
}details;

struct details d;

void subjects_assign(struct details *d)
{
        strcpy(d->subjects[0], "English");
        strcpy(d->subjects[1], "Tamil");
        strcpy(d->subjects[2], "Maths");
        strcpy(d->subjects[3], "DPCO");
        strcpy(d->subjects[4], "Value Education");
        strcpy(d->subjects[5], "P.E");
        strcpy(d->subjects[6], "C-Lab");
        strcpy(d->subjects[7], "Excel");;
}