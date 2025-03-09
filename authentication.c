#include <stdio.h>
#include <string.h>
#include <unistd.h>

char *nameList[] = {"Alice", "Bob", "Oscar", "Eve", "Doe"};
char *pwdList[] = {"Ali2023", "Bob#456", "Oscar$789", "Eve0012", "Doe#345"};

int authenticate(const char *username, const char *password)
{
    int num_users = sizeof(nameList) / sizeof(nameList[0]);
    for (int i = 0; i < num_users; i++)
    {
        if (strcmp(nameList[i], username) == 0 && strcmp(pwdList[i], password) == 0)
        {
            return 1;
        }
    }
    return 0;
}

int main()
{
    char username[30];
    char *password;
    int counter = 0;

    printf("Enter your username: ");
    while(counter < 3)
{
    if(authenticate(username, password) == 1)
    {
        printf("Authentication successful\n");
        break;
    }
    else
    {
        printf("Authentication failed :( Try again...\n");
        counter++;
        if(counter == 3)
        {
            printf("Limit exceeded! Try later.\n");
            break;
        }
        password = getpass("Enter your password again: ");
    }
}
return 0;
