#include <stdio.h>
#include <string.h>
#include "nurse.h"
#include "helpers.h"

void nurseMain(Database mockdatabase) {
    while (1) {
        if (puts("1. Search a patient")){}
        if (puts("2. Go back")){}
        int nurseOption;
        nurseOption = getNumericResponse();
        if (nurseOption > 0) {
            if (nurseOption == 1) {
                findingPatientNurse(mockdatabase);
            }
            if (nurseOption == 2) {
                if (puts("Exiting out")){}
                return;
            }
        } else {
            if (puts("You did not input a correct number.")){}
        }
    }
}

void findingPatientNurse(Database mockdatabase) {
    if (puts("Please input the id of the patient you would like to search")){}
    int id;
    id = getNumericResponse();
    if (id == 0) {
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
