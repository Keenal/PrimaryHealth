#include <stdio.h>
#include <string.h>
#include "admin.h"
#include "helpers.h"

void adminMain(Database mockdatabase) {

    int dummyint;
    long result;
    while (1) {
        dummyint = puts("1. Create a patient.");
        dummyint = puts("2. Delete a patient.");
        dummyint = puts("3. Logout.");
        if (dummyint){}

        result = getNumericResponse();
        if (result > 0) {
            if (result == 1) {
                makePatient(mockdatabase);
            } else if (result == 2) {
                deletingPatient(mockdatabase);
            } else if (result == 3) {
                dummyint = puts("Logging out");
                break;
            }
        } else {
            dummyint = puts("You must put a number representing one of the options. Ex: For option 1 you would type \"1\"");
        }
    }
}

void makePatient(Database mockdatabase) {

    int dummyint;
    int result = 0;
    char * dummycharptr;

    dummyint = puts("What is the patient's name?");
    if (dummyint) {}
    char name[MAX_NAME_SIZE];
    dummycharptr = fgets(name, sizeof(name), stdin);
    if (dummycharptr){}
    if (strlen(name) <= 0) {
        dummyint = puts(
                "You did not enter a valid patient name. Patient names must be greater than 0 and less than 32 characters, please try again.");
        return;
    }

    result = puts("What is the patient's id?");
    long id;
    id = getNumericResponse();
    if (result == 0) {
        dummyint = puts("You must put a number representing a unique id for the patient");
        return;
    }

    dummyint = puts("What is the patient's date of birth? Ex: 01161997 represents January 16th, 1997.");
    int dob;
    dob = getNumericResponse();
    if (dob == 0) {
        dummyint = puts("You did not input a number. You must put a number representing the patients date of birth. Ex: 01161997 represents January 16th, 1997.");
        return;
    }

    dummyint = puts("What is the patient's gender? Ex: M for male or F for female.");
    char gender;
    char buffer[MAX_RESPONSE];
    dummycharptr = fgets(buffer, sizeof(buffer), stdin);
    result = sscanf(buffer, "%c", &gender);
    if (result <= 0) {
        dummyint = puts(
                "You did not input a character. You must put a character representing a unique id for the patient");
        return;
    }

    dummyint = puts("What is the patient's height? Ex: 60 for some person who is 5 feet tall.");
    double height;
    height = (double)getNumericResponse();
    if (result == 0) {
        dummyint = puts(
                "You did not input a number. You must put a number representing the patient's height. Ex: 60 for some person who is 5 feet tall.");
        return;
    }

    dummyint = puts("What is the patient's weight? Ex: 150 for someone who weighs 150lb.");
    double weight;
    weight = (double)getNumericResponse();
    if (weight == 0) {
        dummyint = puts(
                "You must put a number representing the patient's weight. Ex: 150 for someone who weights 150lb.");
        return;
    }

    Patient newPatient;
    newPatient = createPatient(name, id, dob, gender, height, weight);
    addPatient(mockdatabase, newPatient);
    printPatients(mockdatabase);
}

void deletingPatient(Database mockdatabase) {

    int dummyint;
    dummyint = puts("Please input the id of the patient you would like to search");
    if (dummyint){}

    int id;
    id = getNumericResponse();
    if (id == 0) {
        dummyint = puts("This is not a valid patient id.");
        return;
    }

    Patient patientToFind;
    patientToFind = findPatient(mockdatabase, id);
    if (patientToFind == NULL) {
        dummyint = puts("This patient ID does not match our database");
        return;
    } else {
        deletePatient(mockdatabase, id);
        dummyint = puts("Your requested patient has been removed from this database");
    }
}

