#include <stdio.h>
#include <stdlib.h>
#include "database.h"

struct database
{

    Patient patients[MAX_PATIENTS_SIZE];
    int size;
};

Database createDatabase()
{

    Database database = malloc(sizeof(struct database));
    if (database == NULL) return NULL;
    database->size = 0;

    return database;
}

void addPatient(Database database, Patient newPatient)
{

    if (database->size < MAX_PATIENTS_SIZE)
    {

        database->patients[database->size] = newPatient;
        database->size++;
    }
    else
    {

        puts("Maximum number of patients reached. Unable to add new patient");
    }
}

Patient findPatient(Database database, int id)
{

    int i;
    for (i = 0; i < database->size; i++)
    {

        if (getPatientID(database->patients[i]) == id)
        {

            return database->patients[i];
        }
    }

    return NULL;
}

void printPatients(Database database)
{

    int i;
    for (i = 0; i < database->size; i++)
    {

        printPatient(database->patients[i]);
        puts("");
    }
}

void freeDatabase(Database database)
{

    int i;
    for (i = 0; i < database->size; i++)
    {

        free(database->patients[i]);
    }

    free(database);
}

void deletePatient(Database database, int id)
{
    int i;
    for (i = 0; i < database->size - 1; i++)
    {
        if (getPatientID(database->patients[i]) == id && database->patients[i] != NULL)
        {
            free(database->patients[i]);
            int j;
            for (j = i; j < database->size - 1; j++)
            {
                database->patients[j] = database->patients[j + 1];
            }

            database->size--;
            break;
        }
    }
}
