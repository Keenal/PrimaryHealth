#ifndef DOC_H_
#define DOC_H_

#include "database.h"
#include "patient.h"

#define MAX_RESPONSE 1024

void docMain(Database database);
void changePatient(Database database);
void findingPatient(Database database);
void printingAllPatients(Database database);

#endif /* doc_H_ */
