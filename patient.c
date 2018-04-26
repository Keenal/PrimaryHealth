#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "patient.h"
#include "helpers.h"

struct patient {

    char name[MAX_NAME_SIZE];
    int id;
    int dob;
    char gender;
    double height;
    double weight;
};

Patient createPatient(const char *name, int id, int dob, char gender, double height, double weight) {

    Patient newPatient;
    newPatient = malloc(sizeof(struct patient));
    if (newPatient == NULL) return NULL;
    memset(newPatient->name, '\0', sizeof(newPatient->name));
    if (strlen(name) < MAX_NAME_SIZE - 1) {

        strncpy(newPatient->name, name, strlen(name));
        newPatient->id = id;
        newPatient->dob = dob;
        newPatient->gender = gender;
        newPatient->height = height;
        newPatient->weight = weight;
        printf("Patient Name: %s\n", newPatient->name);
        return newPatient;
    } else {

        return NULL;
    }
}

int getPatientID(Patient pat) {
    return pat->id;
}

void editPatient(Patient pat) {

    while (1) {

        if (puts("Which of the following would you like to edit:")){}
        printf("1. Name: %s\n", pat->name);
        printf("2. DOB: %08d\n", pat->dob);
        printf("3. Gender: %c\n", pat->gender);
        printf("4. Height: %.2lf\n", pat->height);
        printf("5. Weight: %.2lf\n", pat->weight);
        if (puts("Or enter 6 to go back.")){}

        char buffer[MAX_NAME_SIZE];
        long option;
        option = getNumericResponse();
        if (option > 0) {
            switch (option) {
                case 1:
                    if (puts("What would you like the new name to be?")){}
                    char name[MAX_NAME_SIZE];
                    char *charptr;
                    charptr = fgets(name, sizeof(name), stdin);
                    if (charptr){}
                    if (strlen(name) <= 0) {
                        if (puts("You did not enter a valid patient name. Patient names must be greater than 0 and less than 32 characters, please try again.")){}
                        continue;
                    }
                    memset(pat->name, '\0', sizeof(pat->name));
                    strncpy(pat->name, name, strlen(name));
                    break;
                case 2:
                    if (puts("What would you like the new date of birth to be?")){}
                    int dob;
                    dob = (int)getNumericResponse();
                    if (dob == 0) {
                        if (puts("You did not input a number. You must put a number representing the patients date of birth. Ex: 01161997 represents January 16th, 1997.")){}
                        continue;
                    }
                    pat->dob = dob;
                    break;
                case 3:
                    if (puts("What would you like the new gender to be?")){}
                    char gender;
                    charptr = fgets(buffer, sizeof(buffer), stdin);
                    if (charptr){}
                    int result;
                    result = sscanf(buffer, "%c", &gender);
                    if (result <= 0) {
                        if (puts("You did not input a character. You must put a character representing a unique id for the patient")){}
                        continue;
                    }
                    pat->gender = gender;
                    break;
                case 4:
                    if (puts("What would you like the new height to be?")){}
                    double height;
                    height = (double)getNumericResponse();
                    if (height == 0) {
                        if (puts("You did not input a number. You must put a number representing the patient's height. Ex: 60 for some person who is 5 feet tall.")){}
                        continue;
                    }
                    pat->height = height;
                    break;
                case 5:
                    if (puts("What would you like the new weight to be?")){}
                    double weight;
                    weight = (double)getNumericResponse();
                    if (result == 0) {
                        if (puts("You did not input a number. You must put a number representing the patient's weight. Ex: 150 for someone who weights 150lb.")){}
                        continue;
                    }
                    pat->weight = weight;
                    break;
                case 6:
                    if (puts("Returning back to previous menu...")){}
                    return;
                default:
                    if (puts("Invalid option selected.")) {}
            }
        }
    }
}

void printPatient(Patient pat) {

    printf("Name: %s\n", pat->name);
    printf("ID: %d\n", pat->id);
    printf("DOB: %d\n", pat->dob);
    printf("Gender: %c\n", pat->gender);
    printf("Height: %.2lf\n", pat->height);
    printf("Weight: %.2lf\n", pat->weight);
}
