#include <stdio.h>
#include <stdlib.h>
int x,z;
void vote()
{ int n;
        FILE *p;
    for(int i=1; i<=x; i++)
    {
        system("cls");
        int c;
        FILE *file;
        file = fopen("candidates.txt", "r");
        while ((c = getc(file)) != EOF)
        {
            putchar(c);
        }
        printf("Please enter the Number of the person you want to vote :\n");

        p=fopen("Votes.txt","a");
        scanf("%d",&n);
        fprintf(p,"%d",n);

    }fclose(p);
    getchar();
    choice();
}

void cdname()
{
    printf("\nPlease enter the number of Voters\n");
    scanf("%d",&x);
    printf("\nPlease enter the number of candidates\n");
    scanf("%d",&z);
    FILE  *y;
    y=fopen("candidates_number.txt","w+");
    fprintf(y,"%d",z);
    char name[100];
    FILE *fptr;
    fptr = fopen("candidates.txt","w+");

    if(fptr == NULL)
    {
        printf("Error!");
        exit(1);
    }

    printf("Enter names:\n");
    getchar();
    for(int i=1; i<=z; i++)
    {
        printf("%d. ",i);
        gets(name);
        fprintf(fptr,"%d. %s\n",i,name);
    }

    fclose(fptr);
    FILE *p;
    p=fopen("Votes.txt","w");
    {
        int a;
        printf("\n\n\npress 1 to go back to main menu\n");
        scanf("%d",&a);
        if(a==1)
        {
            getchar();
            choice();
        }
        else
        {
            return 0;
        }
    }

}
void results()
{
    system("cls");
    {
        int z;

        FILE *y;
        y=fopen("candidates_number.txt","r");
        fscanf(y,"%d",&z);
        char n[50];

        FILE *p;
        p=fopen("votes.txt","r");
        fscanf(p,"%s",&n);

        {
            int total_number = strlen(n);
            int counting[5] = {0};
            for (int i = 0; i < total_number; i++)
            {
                counting[n[i] - '0']++;
            }
            int max_occurred = 0;
            int max_nums_length = 0;
            int max_nums[50] = {0};
            for (int i = 1; i <= z; i++)
            {
                printf("Candidate number %d got:  %d votes\n", i, counting[i]);
                if (max_occurred < counting[i])
                {
                    max_occurred = counting[i];
                    max_nums_length = 0;
                    max_nums[++max_nums_length] = i;
                }
                else if (max_occurred == counting[i])
                {
                    max_nums[++max_nums_length] = i;
                }
            }
            printf("The winner is Candidate number:  ");
            for (int i = 1; i <= max_nums_length; i++)
            {
                printf("%d  ", max_nums[i]);
            }
            printf("\n");
        }
    }
    int a;
    printf("\n\n\npress 1 to go back to main menu\n");
    scanf("%d",&a);
    if(a==1)
    {
        getchar();
        choice();
    }
    else
    {
        return 0;
    }
}

void adminpanel()
{
    system("cls");
    char a;
    int n;
    printf("Please enter the password :\n");
    scanf("%d",&n);
    getchar();
    system("cls");
    if(n==8287)
    {
        printf("1.Input Candidates and Voters data\n2.Show the results\n3.goto main menu\n");
        scanf("%c",&a);
        switch(a)
        {
        case '1':
            cdname();
            break;
        case '2':
            results();
            break;

        case'3':
            {
                getchar();
                choice();
                break;
            }
            default:
            printf("\nInvalid option\nPlease press 1 or 2\n");
        }
    }
    else
    {
        printf("invalid password");
          int a;
    printf("\n\n\npress 1 to go back to main menu\n");
    scanf("%d",&a);
    if(a==1)
    {
        getchar();
        choice();
    }
    else
    {
        return 0;
    }
    }
}
void choice()
{
    system("cls");
    printf("*********** Election System for Class Representative(CR)**************\n");
    printf("1.Vote\n2.Admin panel\n3.Exit\n\n\nPlease press numbers to select options\n");
    char n;
    scanf("%c",&n);
    switch(n)
    {
    case '1':
        vote();
        break;
    case '2':
        adminpanel();
    case '3':
        return 0;
    default:
    {
        printf("Invalid input\n Please press 1,2 or 3\n");
    }

    }

}
int main()
{
    choice();
    return 0;
}
