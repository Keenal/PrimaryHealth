#include <stdio.h>
#include <stdlib.h>
#include "menus.h"
#include "patient.h"
#include "database.h"
#include "admin.h"

void start();
void handleInput(int, Database);

int main(int argc, char** argv)
{

    puts("\nWelcome to the PrimaryHealth application!\n");
    start();

}

void start()
{

    Database database = createDatabase();

    int ans = 0;
    while (1)
    {

        displayMainMenu();
		int result = scanf("%d", &ans);
        if (result > 0)
        {

            printf("User inputted: %d\n", ans);
            handleInput(ans, database);

        }
        else
        {

            puts("You did not input a number. You must put a number representing one of the options. Ex: For option 1 you would type \"1\"");

        }

    }

    freeDatabase(database);

}

void handleInput(int option, Database database)
{

    if (option == 1)
    {

        puts("You are logged in as a Doctor.\n");
    }
    else if (option == 2)
    {

        puts("You are logged in as a Nurse.");
	
	

    }
    else if (option == 3)
    {

        puts("You are logged in as an Admin.");
        adminMain(database);

    }
	else if(option == 4){
	    puts("Exiting the program");
	    exit(0);
    }
    else
    {

        puts("Invalid option selected...");

    }

}
