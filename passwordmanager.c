#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
int i;

typedef struct
{
    char username[50];
    char password[30];
    char type[30];
} Password;

Password passwords[30];
int passwordCount = 0;

void addNewPassword()
{
    system("cls");
    if (passwordCount >= 30)
    {
        printf("Error: Maximum number of passwords reached.\n");
        return;
    }
    Password newPassword;
    printf("Enter the account type(Facebook Instagram / Other) : ");
    scanf("%s", newPassword.type);
    printf("Enter username: ");
    scanf("%s", newPassword.username);
    printf("Enter password: ");
    scanf("%s", newPassword.password);

    passwords[passwordCount] = newPassword;
    passwordCount++;

    printf("Added successfully.\n");
}

void viewPasswords()
{
    system("cls");
    if (passwordCount == 0)
    {
        printf("No passwords found.\n");
        return;
    }
    printf("Stored Passwords:\n");
    printf("---------------------------------------------------------------------\n");
    printf("| %-5s | %-20s | %-25s | %-2s \n", "Index", "Account Type", "Username", "Password");
    printf("---------------------------------------------------------------------\n");
    for (i = 0; i < passwordCount; i++)
    {
        printf("| %-5d | %-20s | %-25s | %-10s \n", i + 1, passwords[i].type, passwords[i].username, passwords[i].password);
    }
    printf("---------------------------------------------------------------------\n");
}

void updatePass()
{
    int index;
    printf("Enter the index of the password to update: ");
    scanf("%d", &index);
    index--;

    if (index < 0 || index >= passwordCount)
    {
        printf("Invalid index.\n");
        return;
    }

    printf("Enter new username: ");
    scanf("%s", passwords[index].username);

    printf("Enter new password: ");
    scanf("%s", passwords[index].password);

    printf("Password updated successfully.\n");
}

void deletePassword()
{
    int index;
    printf("Enter the index of the password to delete: ");
    scanf("%d", &index);
    index--;

    if (index < 0 || index >= passwordCount)
    {
        printf("Invalid index.\n");
        return;
    }

    FILE *file = fopen("passwords.txt", "r");
    FILE *replaceFile = fopen("replace.txt", "w");

    if (file == NULL || replaceFile == NULL)
    {
        printf("Error: Unable to open file for reading or writing.\n");
        return;
    }

    int presentIdx = 0;
    char username[50];
    char password[30];

    while (fscanf(file, "%[^:]:%s\n", username, password) != EOF)
    {
        if (presentIdx != index)
        {
            fprintf(replaceFile, "%s:%s\n", username, password);
        }
        presentIdx++;
    }

    fclose(file);
    fclose(replaceFile);

    for (int i = index; i < passwordCount - 1; i++)
    {
        passwords[i] = passwords[i + 1];
    }

    passwordCount--;

    printf("Password deleted successfully.\n");
}

void savePass()
{
    system("cls");
    FILE *file = fopen("passwords.txt", "w");
    if (file == NULL)
    {
        printf("Error: Unable to open file for writing.\n");
        return;
    }

    for (int i = 0; i < passwordCount; i++)
    {
        fprintf(file, "%s:%s\n", passwords[i].username, passwords[i].password);
    }

    fclose(file);

    printf("Passwords saved to file.\n");
}

void loadPass()
{
    system("cls");  
    FILE *file = fopen("passwords.txt", "r");
    if (file == NULL)
    {
        printf("Error: There is no password stored in file.\n");
        return;
    }

    passwordCount = 0;
    while (fscanf(file, "%[^:]:%s\n", passwords[passwordCount].username, passwords[passwordCount].password) != EOF)
    {
        passwordCount++;
    }

    fclose(file);
}

int main()
{
    char choice;

    loadPass();

    do
    {
        system("cls");
        printf("\nPassword Manager Menu:\n");
        printf("1. Add Password\n");
        printf("2. View Passwords\n");
        printf("3. Update Password\n");
        printf("4. Delete Password\n");
        printf("5. Save Passwords to File\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf(" %c", &choice);

        switch (choice)
        {
        case '1':
            addNewPassword();
            break;
        case '2':
            viewPasswords();
            break;
        case '3':
            viewPasswords();
            updatePass();

            break;
        case '4':
            viewPasswords();
            deletePassword();
            break;
        case '5':
            savePass();
            break;
        case '6':
            printf("Exiting...\n");
            exit(0);
            break;
        default:
            printf("Invalid choice. Please try again.\n");
        }
        printf("Press any key to continue..");
        getch();
    }while (choice !='6');
    return 0;
}
