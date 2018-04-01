#ifndef DATABASE_H_
#define DATABASE_H_

#include "patient.h"

#define MAX_PATIENTS_SIZE 32

typedef struct database* Database;

Database createDatabase();
void addPatient(Database database, Patient newPatient);
Patient findPatient(Database database, int id);
void printPatients(Database database);
void freeDatabase(Database database);
void deletePatient(Database database, int id);

#endif /* USER_H_ */
