#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "patient.h"


struct patient
{

    char name[MAX_NAME_SIZE];
    int id;
    int dob;
    char gender;
    double height;
    double weight;

};

Patient createPatient(const char* name, int id, int dob, char gender, double height, double weight)
{

    Patient newPatient = malloc(sizeof(struct patient));
    memset(newPatient->name, '\0', sizeof(newPatient->name));
    if (strlen(name) < MAX_NAME_SIZE - 1)
    {

        strncpy(newPatient->name, name, strlen(name));
        newPatient->id = id;
        newPatient->dob = dob;
        newPatient->gender = gender;
        newPatient->height = height;
        newPatient->weight = weight;
        printf("Patient Name: %s\n", newPatient->name);
        return newPatient;

    }
    else
    {

        return NULL;

    }


}

int getPatientID(Patient patient)
{

    return patient->id;

}

void editPatient(Patient patient)
{


    while(1)
    {

        puts("Which of the following would you like to edit:");
        printf("1. Name: %s\n", patient->name);
        printf("2. DOB: %08d\n", patient->dob);
        printf("3. Gender: %c\n", patient->gender);
        printf("4. Height: %.2lf\n", patient->height);
        printf("5. Weight: %.2lf\n", patient->weight);
        puts("Or enter 6 to go back.");

        char buffer[MAX_NAME_SIZE];
        int option;
        fgets(buffer, sizeof(buffer), stdin);
        int result = sscanf(buffer, "%d", &option);
        if (result > 0)
        {

            if (option == 1)
            {

                puts("What would you like the new name to be?");
                char name[MAX_NAME_SIZE];
                fgets(name, sizeof(name), stdin);
                if (strlen(name) <= 0)
                {

                    puts("You did not enter a valid patient name. Patient names must be greater than 0 and less than 32 characters, please try again.");
                    continue;

                }

                
                memset(patient->name, '\0', sizeof(patient->name));
                strncpy(patient->name, name, strlen(name));

            }
            else if (option == 2)
            {

                puts("What would you like the new date of birth to be?");
                int dob;
                fgets(buffer, sizeof(buffer), stdin);
                result = sscanf(buffer, "%d", &dob);
                if (result <= 0)
                {

                    puts("You did not input a number. You must put a number representing the patients date of birth. Ex: 01161997 represents January 16th, 1997.");
                    continue;

                }

                patient->dob = dob;


            }
            else if (option == 3)
            {

                puts("What would you like the new gender to be?");

                char gender;
                fgets(buffer, sizeof(buffer), stdin);
                result = sscanf(buffer, "%c", &gender);
                if (result <= 0)
                {

                    puts("You did not input a character. You must put a character representing a unique id for the patient");
                    continue;

                }

                patient->gender = gender;

            }
            else if (option == 4)
            {

                puts("What would you like the new height to be?");

                double height;
                fgets(buffer, sizeof(buffer), stdin);
                result = sscanf(buffer, "%lf", &height);
                if (result <= 0)
                {

                    puts("You did not input a number. You must put a number representing the patient's height. Ex: 60 for some person who is 5 feet tall.");
                    continue;

                }

                patient->height = height;


            }
            else if (option == 5)
            {

                puts("What would you like the new weight to be?");

                double weight;
                fgets(buffer, sizeof(buffer), stdin);
                result = sscanf(buffer, "%lf", &weight);
                if (result <= 0)
                {

                    puts("You did not input a number. You must put a number representing the patient's weight. Ex: 150 for someone who weights 150lb.");
                    continue;

                }

                patient->weight = weight;

            }
            else if (option == 6)
            {

                puts("Returning back to previous menu...");
                return;

            }
            else
            {

                puts("Invalid option selected.");

            }

        }

    }
    
}

void printPatient(Patient patient)
{

    printf("Name: %s\n", patient->name);
    printf("ID: %d\n", patient->id);
    printf("DOB: %d\n", patient->dob);
    printf("Gender: %c\n", patient->gender);
    printf("Height: %.2lf\n", patient->height);
    printf("Weight: %.2lf\n", patient->weight);

}
