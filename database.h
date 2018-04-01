#ifndef DATABASE_H_
#define DATABASE_H_

#include "patient.h"

#define MAX_PATIENTS_SIZE 32

typedef struct database* Database;

Database createDatabase();
void addPatient(Database database, Patient newPatient);
void printPatients(Database database);
void freeDatabase(Database database);

#endif /* USER_H_ */