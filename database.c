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