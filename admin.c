#include <stdio.h>
#include <string.h>
#include "admin.h"

void adminMain(Database database)
{

    char buffer[MAX_RESPONSE];
    while (1)
    {

        puts("1. Create a patient.");
        puts("2. Delete a patient.");
        //	printf("3. Logout");
        puts("3. Logout.");

        int adminOption;
        //        fgets(buffer, sizeof(buffer), stdin);
        //       int result = sscanf(buffer, "%d", &adminOption);
        int result = scanf("%d", &adminOption);
        if (result > 0)
        {

            if (adminOption == 1)
            {

                makePatient(database);
            }
            else if (adminOption == 2)
            {

                deletingPatient(database);
            }
            else if (adminOption == 3)
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

void makePatient(Database database)
{

    puts("What is the patient's name?");
    char name[MAX_NAME_SIZE];
    fgets(name, sizeof(name), stdin);
    if (strlen(name) <= 0)
    {

        puts("You did not enter a valid patient name. Patient names must be greater than 0 and less than 32 characters, please try again.");
        return;
    }

    puts("What is the patient's id?");
    int id;
    char buffer[MAX_RESPONSE];
    fgets(buffer, sizeof(buffer), stdin);
    int result = sscanf(buffer, "%d", &id);
    if (result <= 0)
    {

        puts("You did not input a number. You must put a number representing a unique id for the patient");
        return;
    }

    puts("What is the patient's date of birth? Ex: 01161997 represents January 16th, 1997.");
    int dob;
    fgets(buffer, sizeof(buffer), stdin);
    result = sscanf(buffer, "%d", &dob);
    if (result <= 0)
    {

        puts("You did not input a number. You must put a number representing the patients date of birth. Ex: 01161997 represents January 16th, 1997.");
        return;
    }

    puts("What is the patient's gender? Ex: M for male or F for female.");
    char gender;
    fgets(buffer, sizeof(buffer), stdin);
    result = sscanf(buffer, "%c", &gender);
    if (result <= 0)
    {

        puts("You did not input a character. You must put a character representing a unique id for the patient");
        return;
    }

    puts("What is the patient's height? Ex: 60 for some person who is 5 feet tall.");
    double height;
    fgets(buffer, sizeof(buffer), stdin);
    result = sscanf(buffer, "%lf", &height);
    if (result <= 0)
    {

        puts("You did not input a number. You must put a number representing the patient's height. Ex: 60 for some person who is 5 feet tall.");
        return;
    }

    puts("What is the patient's weight? Ex: 150 for someone who weighs 150lb.");
    double weight;
    fgets(buffer, sizeof(buffer), stdin);
    result = sscanf(buffer, "%lf", &weight);
    if (result <= 0)
    {

        puts("You did not input a number. You must put a number representing the patient's weight. Ex: 150 for someone who weights 150lb.");
        return;
    }

    Patient newPatient = createPatient(name, id, dob, gender, height, weight);

    addPatient(database, newPatient);
    printPatients(database);
}

void deletingPatient(Database database)
{
    puts("Please input the id of the patient you would like to search");

    int id;
    int result = scanf("%d", &id);
    if (result <= 0)
    {
        puts("This is not a valid patient id.");
        return;
    }

    Patient patientToFind = findPatient(database, id);
    deletePatient(database, id);
    if (patientToFind == NULL)
    {
        puts("This patient ID does not match our database");
        return;
    }
    else
    {
        puts("Your requested patient has been removed from this database");
    }
}
