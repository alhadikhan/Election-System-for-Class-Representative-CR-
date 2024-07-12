# Election System for Class Representative (CR)

This project, developed as a first-year C programming project, is an election system designed to facilitate the election of a Class Representative (CR) among students. The system includes functionalities for both voters and administrators, ensuring a smooth and secure election process. The following sections describe the features and implementation details of the project.

## Features

### Voter Interface

- **Vote Casting**: Students can cast their votes by selecting the number corresponding to their preferred candidate.
- **Candidate Display**: The system reads and displays the list of candidates from a file before allowing the voter to cast their vote.

### Administrator Interface

- **Input Candidates and Voters Data**: Administrators can input the number of voters and candidates, and enter the names of the candidates.
- **Show Results**: The system counts the votes for each candidate and displays the results, including the candidate with the highest votes.
- **Password Protection**: Access to the administrator panel is protected by a password to ensure that only authorized personnel can input data and view results.

## Implementation

### Files

- **candidates.txt**: Stores the names of the candidates.
- **Votes.txt**: Stores the votes cast by students.
- **candidates_number.txt**: Stores the total number of candidates.

### Functions

- `vote()`: Handles the voting process, reads the list of candidates, and records the vote.
- `cdname()`: Allows administrators to input the number of voters and candidates, and enter the candidate names.
- `results()`: Reads the votes and counts them to determine and display the election results.
- `adminpanel()`: Provides access to the administrator functionalities, including inputting data and viewing results.
- `choice()`: Main menu that provides options to vote, access the admin panel, or exit the system.
- `main()`: Entry point of the program that calls the `choice()` function.

## Code

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int x, z;

void vote() {
    int n;
    FILE *p;
    for (int i = 1; i <= x; i++) {
        system("cls");
        int c;
        FILE *file;
        file = fopen("candidates.txt", "r");
        while ((c = getc(file)) != EOF) {
            putchar(c);
        }
        printf("Please enter the Number of the person you want to vote:\n");

        p = fopen("Votes.txt", "a");
        scanf("%d", &n);
        fprintf(p, "%d", n);
        fclose(file);
    }
    fclose(p);
    getchar();
    choice();
}

void cdname() {
    printf("\nPlease enter the number of Voters\n");
    scanf("%d", &x);
    printf("\nPlease enter the number of candidates\n");
    scanf("%d", &z);
    FILE *y;
    y = fopen("candidates_number.txt", "w+");
    fprintf(y, "%d", z);
    char name[100];
    FILE *fptr;
    fptr = fopen("candidates.txt", "w+");

    if (fptr == NULL) {
        printf("Error!");
        exit(1);
    }

    printf("Enter names:\n");
    getchar();
    for (int i = 1; i <= z; i++) {
        printf("%d. ", i);
        gets(name);
        fprintf(fptr, "%d. %s\n", i, name);
    }

    fclose(fptr);
    FILE *p;
    p = fopen("Votes.txt", "w");
    fclose(p);

    int a;
    printf("\n\n\npress 1 to go back to main menu\n");
    scanf("%d", &a);
    if (a == 1) {
        getchar();
        choice();
    } else {
        exit(0);
    }
}

void results() {
    system("cls");
    int z;

    FILE *y;
    y = fopen("candidates_number.txt", "r");
    fscanf(y, "%d", &z);
    fclose(y);
    char n[50];

    FILE *p;
    p = fopen("Votes.txt", "r");
    fscanf(p, "%s", n);
    fclose(p);

    int total_number = strlen(n);
    int counting[10] = {0};
    for (int i = 0; i < total_number; i++) {
        counting[n[i] - '0']++;
    }
    int max_occurred = 0;
    int max_nums_length = 0;
    int max_nums[50] = {0};
    for (int i = 1; i <= z; i++) {
        printf("Candidate number %d got:  %d votes\n", i, counting[i]);
        if (max_occurred < counting[i]) {
            max_occurred = counting[i];
            max_nums_length = 0;
            max_nums[++max_nums_length] = i;
        } else if (max_occurred == counting[i]) {
            max_nums[++max_nums_length] = i;
        }
    }
    printf("The winner is Candidate number:  ");
    for (int i = 1; i <= max_nums_length; i++) {
        printf("%d  ", max_nums[i]);
    }
    printf("\n");

    int a;
    printf("\n\n\npress 1 to go back to main menu\n");
    scanf("%d", &a);
    if (a == 1) {
        getchar();
        choice();
    } else {
        exit(0);
    }
}

void adminpanel() {
    system("cls");
    char a;
    int n;
    printf("Please enter the password:\n");
    scanf("%d", &n);
    getchar();
    system("cls");
    if (n == 8287) {
        printf("1.Input Candidates and Voters data\n2.Show the results\n3.goto main menu\n");
        scanf("%c", &a);
        switch (a) {
            case '1':
                cdname();
                break;
            case '2':
                results();
                break;
            case '3':
                getchar();
                choice();
                break;
            default:
                printf("\nInvalid option\nPlease press 1 or 2\n");
        }
    } else {
        printf("Invalid password");
        int a;
        printf("\n\n\npress 1 to go back to main menu\n");
        scanf("%d", &a);
        if (a == 1) {
            getchar();
            choice();
        } else {
            exit(0);
        }
    }
}

void choice() {
    system("cls");
    printf("*********** Election System for Class Representative (CR) **************\n");
    printf("1.Vote\n2.Admin panel\n3.Exit\n\n\nPlease press numbers to select options\n");
    char n;
    scanf("%c", &n);
    switch (n) {
        case '1':
            vote();
            break;
        case '2':
            adminpanel();
            break;
        case '3':
            exit(0);
        default:
            printf("Invalid input\n Please press 1, 2, or 3\n");
    }
}

int main() {
    choice();
    return 0;
}
