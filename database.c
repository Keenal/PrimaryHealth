#include <stdio.h>
#include <stdlib.h>
#include "database.h"

struct database
{

    User users[MAX_USERS_SIZE];
    int size;

};

Database createDatabase()
{

    Database database = malloc(sizeof(Database));
    database->size = 0;

    return database;

}

void addUser(Database database, User newUser)
{

    if (database->size < MAX_USERS_SIZE)
    {

        database->users[database->size] = newUser;
        database->size++;

    }
    else
    {

        puts("Maximum number of users reached. Unable to add new user");

    }

}

void printUsers(Database database)
{

    int i;
    for (i = 0; i < database->size; i++)
    {

        printUser(database->users[i]);

    }

}

void freeDatabase(Database database)
{

    int i;
    for (i = 0; i < database->size; i++)
    {

        free(database->users[i]);

    }

    free(database);

}