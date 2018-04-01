#include <stdio.h>
#include <string.h>
#include "doc.h"

void docMain(Database database)
{

    char buffer[MAX_RESPONSE];
    while(1)
    {

        puts("1. Edit a patient.");
        puts("2. Search a patient.");
        puts("3. Print all patients.");
        puts("4. Logout.");

        int docOption;
        fgets(buffer, sizeof(buffer), stdin);
        int result = sscanf(buffer, "%d", &docOption);
        if (result > 0)
        {

            if (docOption == 1)
            {

                changePatient(database);

            }
            else if (docOption == 2)
            {

                puts("Searching a patient");

            }
            else if (docOption == 3)
            {

                puts("Printing all patients");

            }
            else if (docOption == 4)
            {

                puts("Logging out");
                break;

            }

        }
        else
        {

            puts("You did not input a number. You must put a number representing one of the options. Ex: For option 1 you would type \"1\"");

        }

    }

}

void changePatient(Database database)
{

    puts("Please input the id of the patient you would like to edit:");

    char buffer[MAX_RESPONSE];
    int id;
    fgets(buffer, sizeof(buffer), stdin);
    int result = sscanf(buffer, "%d", &id);
    if (result <= 0)
    {

        puts("You did not input a number. You must put a number representing the id of a patient.");
        return;

    }

    Patient patientToChange = findPatient(database, id);

    if (patientToChange == NULL)
    {

        puts("The id you entered did not match any patient in our records. Please try again.");
        return;

    }

    editPatient(patientToChange);

}