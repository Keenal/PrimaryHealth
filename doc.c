#include <stdio.h>
#include <string.h>
#include "doc.h"
#include "helpers.h"

void docMain(Database mockdatabase) {
    while (1) {
        if (puts("1. Edit a patient.")){}
        if (puts("2. Search a patient.")){}
        if (puts("3. Print all patients.")){}
        if (printf("4. Logout.\n")){}

        long docOption;
        docOption = getNumericResponse();
        if (docOption >= 0) {
            if (docOption == 1) {
                changePatient(mockdatabase);
            } else if (docOption == 2) {
                findingPatient(mockdatabase);
            } else if (docOption == 3) {
                printingAllPatients(mockdatabase);
            } else if (docOption == 4) {
                if (puts("Logging out")){}
                break;
            }
        } else {
            if (puts("You did not input a number. You must put a number representing one of the options. Ex: For option 1 you would type \"1\"")){};
        }
    }
}

void changePatient(Database mockdatabase) {

    if (puts("Please input the id of the patient you would like to edit:")){}
    long id;
    id = getNumericResponse();
    if (id == 0) {
        if (puts("You did not input a number. You must put a number representing the id of a patient.")){}
        return;
    }

    Patient patientToChange;
    patientToChange = findPatient(mockdatabase, id);
    if (patientToChange == NULL) {
        if (puts("The id you entered did not match any patient in our records. Please try again.")){}
        return;
    }
    editPatient(patientToChange);
}

void findingPatient(Database mockdatabase) {
    if (puts("Please input the id of the patient you would like to search")){}
    long id;
    id = getNumericResponse();
    if (id <= 0) {
        if (puts("This is not a valid patient id.")){}
        return;
    }
    Patient patientToFind;
    patientToFind = findPatient(mockdatabase, id);
    printPatients(mockdatabase);
    if (patientToFind == NULL) {
        if (puts("This patient ID does not match our database")){}
        return;
    }
}

void printingAllPatients(Database mockdatabase) {
    if (puts("Printing all patients")){}
    printPatients(mockdatabase);
}
