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

    Patient newPatient = malloc(sizeof(Patient));
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

Patient searchPatient(int id)
{

    return NULL;

}