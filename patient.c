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