#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void signup(char user[], char pw[])
{

    FILE *file = fopen("../data/users.txt", "a");

    if (file != NULL)
    {
        fprintf(file, "%s %s\n", user, pw);
        fclose(file);
        printf("SignedUP Successfully.\n");
    }
    else
    {
        printf("Error\n");
    }
}
int check(char *user, char *pw)
{
    FILE *file = fopen("../data/users.txt", "r");

    if (file != NULL)
    {
        char storeduser[50];
        char storedpw[50];

        while (fscanf(file, "%s %s", storeduser, storedpw) != EOF)
        {
            if (strcmp(user, storeduser) == 0 && strcmp(pw, storedpw) == 0)
            {
                fclose(file);
                return 1;
            }
        }

        fclose(file);
        return 0; 
    }
    else
    {
        printf("Error opening file.\n");
        return -1;
    }
}

int login(char *user, char *pw)
{
    int a;
    a = check(user, pw);
    if (a == 1)
    {
        printf("Loged In Successfully\n");
        return 1;
    }
    else
    {
        printf("User Not found\n");
    again:
        printf("Do you want to sign up ?(yes=1/No=0)\n");
        scanf("%d", &a);
        switch (a)
        {
        case 1:
            signup(user, pw);
            break;
        case 2:
            return 0;
            break;
        default:
            printf("Error Input , try again :\n");
            goto again;
            break;
        }
    }
}

/*void show(char *filename) {
    FILE *file = fopen(filename, "r");

    if (file != NULL) {
        char username[50];
        char password[50];

        while (fscanf(file, "%s %s", username, password) != EOF) {
            printf("Username: %s, Password: %s\n", username, password);
        }

        fclose(file);
    } else {
        printf("Error opening file.\n");
    }
}*/

int main()
{
    char user[10], pw[20];
    int a;
    printf("1.Login\n2.SignUp");
    scanf("%d", &a);
    switch (a)
    {
    case 1:
        printf("Username:");
        scanf("%s", user);
        printf("Password:");
        scanf("%s", pw);
        a = login(user, pw);
        break;
    case 2:
        printf("Please Enter a Username:");
        scanf("%s", user);
        printf("Please Enter a Password:");
        scanf("%s", pw);
        signup(user, pw);
        a = login(user, pw);
        break;
    default:
        break;
    }

    if (a == 1)
    {

        // management treatement here
    }
    else
    {
        return 0;
    }

    return 0;
}