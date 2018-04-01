#ifndef ADMIN_H_
#define ADMIN_H_

#include "database.h"
#include "patient.h"

#define MAX_RESPONSE 1024

void adminMain(Database database);
void makePatient(Database database);
void deletingPatient(Database database);

#endif /* ADMIN_H_ */