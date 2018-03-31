#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "user.h"

struct user
{

    char username[MAX_USERNAME];
    char password[MAX_PASSWORD];
    char role[32];

};

User makeUser()
{

    User newUser = malloc(sizeof(User));
    memset(newUser->role, '\0', sizeof(newUser->role));
    strncpy(newUser->role, "default", 32);

    puts(newUser->role);

    return newUser;

}

void printUser(User user)
{

    puts(user->role);

}