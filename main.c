#include <stdio.h>
#include <stdlib.h>
#include "menus.h"
#include "patient.h"
#include "database.h"

void start();
void handleInput(int);

int main(int argc, char** argv)
{

    puts("Welcome to the PrimaryHealth application!\n");
    start();

}

void start()
{

    int ans = 0;
    puts("How might I help you today?");
    while (1)
    {

        displayMainMenu();
		int result = scanf("%d", &ans);
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

        puts("You are logged in as a Doctor.\n");
        Patient newPatient = createPatient("Jones", 1, 10122019, 'M', 60.3, 180.3);
        Database database = createDatabase();

        addPatient(database, newPatient);
        printPatients(database);

        freeDatabase(database);

    }
    else if (option == 2)
    {

        puts("You are logged in as a Nurse.");
	
	

    }
    else if (option == 3)
    {

        puts("You are logged in as an Admin");
        exit(0);

    }
    else
    {

        puts("Invalid option selected...");

    }

}
