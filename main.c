#include <stdio.h>
#include <stdlib.h>
#include "menus.h"
#include "user.h"

#define MAX_RESPONSE 1024

void start();
void handleInput(int);

int main(int argc, char** argv)
{

    puts("Welcome to the PrimaryHealth application!");
    start();

}

void start()
{

    int ans = 0;
    puts("How might I help you today?");
  //  char buffer[MAX_RESPONSE];
    while (1)
    {

        displayMainMenu();
    //    fgets(buffer, sizeof(buffer), stdin);
		int result = scanf_s("%d", &ans);
     //   int result = scanf_s(buffer, "%d", &ans);
        if (result > 0)
        {

            printf("User inputted: %d\n", ans);
            handleInput(ans);

        }
        else
        {

            puts("You did not input a number. You must put a number representing one of the options. Ex: For option 1 you would type \"1\"");

        }

    }


}

void handleInput(int option)
{

    if (option == 1)
    {

        puts("Creating user...");
        createUser();

    }
    else if (option == 2)
    {

        puts("Logging in...");

    }
    else if (option == 3)
    {

        puts("Exiting...");
        exit(0);

    }
    else
    {

        puts("Invalid option selected...");

    }

}
