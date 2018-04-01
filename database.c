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

void deletePatient(Database database, int id){

int i;
    for (i = 0; i < database->size - 1; i++)
    {

        if (getPatientID(database->patients[i]) == id)
        {

		//int index = patients.indexOf(id);
		//patients.split(index,1);
          //  database->patients[i] = database->patients[i + 1];

        }

    }

}
