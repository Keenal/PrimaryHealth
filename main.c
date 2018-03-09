#include <stdio.h>

#define MAX_RESPONSE 1024

void start();
void displayMainMenu();
void handleCreateUser();

int main(int argc, char** argv)
{

    puts("Welcome to the PrimaryHealth application!");
    start();

}

void start()
{

    int ans = 0;
    puts("How might I help you today?");
    displayMainMenu();
    char buffer[MAX_RESPONSE];
    fgets(buffer, sizeof(buffer), stdin);
    int result = sscanf(buffer, "%d", &ans);
    if (result < 1)
    {

        puts("You did not input a number. You must put a number representing one of the options. Ex: For option 1 you would type \"1\"");
        displayMainMenu();

    }
    else
    {

        printf("User inputed: %d\n", ans);

    }

}

void displayMainMenu()
{

    puts("1. Create User");
    puts("2. Login");
    puts("Please select one of the above options: ");

}
