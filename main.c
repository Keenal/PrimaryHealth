#include <stdio.h>
#include "user.h"
#include "database.h"

void start();

int main(int argc, char** argv)
{

    puts("Welcome to the PrimaryHealth application!");
    start();

}

void start()
{

    puts("Starting application...");
    Database database = createDatabase();
    
    User newUser = makeUser();
    addUser(database, newUser);

    printUsers(database);

    freeDatabase(database);

}