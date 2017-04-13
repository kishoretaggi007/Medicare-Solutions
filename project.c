#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
void delay(unsigned int mseconds)
{
    clock_t goal = mseconds + clock();
    while (goal > clock());
}
struct mdname
{
    char name[30];
}mn[50];
void frontpage();
void selection();
void doctor();
void customer();
void doctoropt();
void addmedicine();
void adddmedicine();
int t,t1;
char password[10],ans[5],medname[20],ans1[5];
int main()
{
    system("cls");
    frontpage();
    selection();
    return 0;
}
void frontpage()
{
    system("cls");

    system("COLOR 42");
    int i=0;
    char s[50]="WELCOME TO NIT MEDICARE SOLUTIONS\n";
    printf("\n\n\n\n\n\t\t");
    while (s[i]!='\0')
    {
        printf("%c",s[i++]);
        delay(75);
    }
    printf("\n \t");
    char z[100]="WE PROVIDE YOU THE BEST INFO ABOUT THE MEDICINE YOU TAKE";
    i=0;
    while (z[i]!='\0')
    {
        printf("%c",z[i++]);
        delay(75);
    }
    char y[100]="TO PROCEED PLEASE PRESS ENTER";
    printf("\n\n\n\n\t\t");
    i=0;
    while (y[i]!='\0')
    {
        printf("%c",y[i++]);
        delay(75);
    }
    getch();
}
void selection()
{
    system("cls");
    system("COLOR E0");
    printf("\n\n\t PLEASE DO THE FOLLOWING SELECTION");
    printf("\n\t 1- DOCTOR\n  \t 2- CUSTOMER\n  \t 3-EXIT\n");
    scanf("%d",&t);
    if (t==1)
    doctor();
    else if (t==2)
    customer();
    else
    exit(0);
}
void doctor()
{
    system("cls");
    system("COLOR B9");
    printf("\n\n\t\t ENTER THE PASSWORD\n\t\t");
    char c;
    int i=0;
    while((c=getch())!=13)
    {
        if (c>=33 && c<=126)
        {
            password[i++]=c;
            printf("*");
        }
        else if (c==8 || c==127 || c==24)
        doctor();
    }
    if (strcmp(password,"cse@nitrr")==0)
    doctoropt();
    else
    {
        printf("\n\t WRONG PASSWORD");
        printf("\n DO YOU WANT TO TRY AGAIN (YES/NO)");
        scanf("%s",&ans);
        if (strcmpi(ans,"YES")==0)
        doctor();
        else
        selection();
    }
}
void customer()
{
    system("cls");
    system("COLOR 70");
    FILE *mp;
    char c;
    printf("\n\n\n\t\t ENTER THE NAME OF MEDICINE:-");
    scanf("%s",&medname);
    mp=fopen(medname,"r");
    while ((c=getc(mp))!=EOF)
    printf("%c",c);
    printf("\n DO YOU WANT TO CHECK ANOTHER MEDICINE(YES/NO)");
    scanf("%s",&ans1);
    if (strcmpi(ans1,"YES")==0)
    customer();
    else
    {
        printf("\n THANK YOU");
        getch();
        selection();
    }
}

void doctoropt()
{
    system("cls");
    system("COLOR D0");
    printf("\n 1- ADD ANOTHER MEDICINE");
    printf("\n 2- ADD DETAILS ON EXSISTING MEDICINE");
    printf("\n 3- KNOW ABOUT A MEDICINE");
    printf("\n 4- GO TO SELECTION PAGE \n");
    scanf("%d",&t1);
    if (t1==1)
    addmedicine();
    if (t1==2)
    adddmedicine();
    if (t1==3)
    customer();
    if (t1==4)
    selection();
}
void addmedicine()
{
    system("cls");
    system("COLOR F1");
    FILE *mp,*mp1;
    mp1=fopen("MEDINAMES","r");
    int i=0,j;
    while (!feof(mp1))
    fscanf(mp1,"%s\n",mn[i++].name);
    fclose(mp1);
    printf("\n ENTER THE MEDICINE NAME:-");
    scanf("%s",&medname);
    for (j=0;j<i;j++)
    {
        if (strcmpi(mn[j].name,medname)==0)
        {
            printf("\n MEDICINE ALREADY EXSISTED");
            getch();
            addmedicine();
        }
    }
    mp1=fopen("MEDINAMES","a");
    fprintf(mp1,"\n%s",medname);
    fclose(mp1);
    mp=fopen(medname,"w");
    char c;
    while ((c=getchar())!=EOF)
    putc(c,mp);
    fclose(mp);
    printf("\n\n DO YOU WANT TO ADD ANOTHER MEDICINE(YES/NO)");
    scanf("%s",&ans1);
    if (strcmpi(ans1,"YES")==0)
    addmedicine();
    else
    printf("\n\n THANK YOU FOR ADDING NEW INFORMATION");
    getch();
    doctoropt();
}
void adddmedicine()
{
    system("cls");
    system("COLOR 40");
    FILE *mp;
    printf("\n Enter medicine name:-");
    scanf("%s",&medname);
    mp=fopen(medname,"a");
    char c;
    while ((c=getchar())!=EOF)
    putc(c,mp);
    fclose(mp);
    printf("\n\n THANK YOU");
    printf("\n DO YOU WANT TO ADD DETAILS OF ANOTHER MEDICINE(YES/NO):-");
    scanf("%s",&ans);
    if (strcmpi(ans,"yes")==0)
    adddmedicine();
    else
    doctoropt();
}
