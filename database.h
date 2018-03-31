#ifndef DATABASE_H_
#define DATABASE_H_

#include "user.h"

#define MAX_USERS_SIZE 32

typedef struct database* Database;

Database createDatabase();
void addUser(Database database, User newUser);
void printUsers(Database database);
void freeDatabase(Database database);

#endif /* USER_H_ */