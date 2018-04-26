#include <stdio.h>
#include <stdlib.h>
#include "database.h"

struct database {
    Patient patients[MAX_PATIENTS_SIZE];
    int size;
};

Database createDatabase() {
    Database mockdatabase = malloc(sizeof(struct database));
    if (mockdatabase == NULL) return NULL;
    mockdatabase->size = 0;
    return mockdatabase;
}

void addPatient(Database mockdatabase, Patient newPatient) {
    if (mockdatabase->size < MAX_PATIENTS_SIZE) {
        mockdatabase->patients[mockdatabase->size] = newPatient;
        mockdatabase->size++;
    } else {
        if (puts("Maximum number of patients reached. Unable to add new patient")){}
    }
}

Patient findPatient(Database mockdatabase, int id) {
    int i;
    for (i = 0; i < mockdatabase->size; i++) {
        if (getPatientID(mockdatabase->patients[i]) == id) {
            return mockdatabase->patients[i];
        }
    }
    return NULL;
}

void printPatients(Database mockdatabase) {
    int i;
    for (i = 0; i < mockdatabase->size; i++) {
        printPatient(mockdatabase->patients[i]);
        if (puts("")){}
    }
}

void freeDatabase(Database mockdatabase) {
    int i;
    for (i = 0; i < mockdatabase->size; i++) {
        free(mockdatabase->patients[i]);
    }
    free(mockdatabase);
    mockdatabase = NULL;
}

void deletePatient(Database mockdatabase, int id) {
    int i;
    for (i = 0; i < mockdatabase->size - 1; i++) {
        if (getPatientID(mockdatabase->patients[i]) == id && mockdatabase->patients[i] != NULL) {
            free(mockdatabase->patients[i]);
            int j;
            for (j = i; j < mockdatabase->size - 1; j++) {
                mockdatabase->patients[j] = mockdatabase->patients[j + 1];
            }
            mockdatabase->size--;
            break;
        }
    }
}
