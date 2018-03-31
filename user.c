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
    newUser->role = "default\0";

    puts(newUser->role);

    return newUser;

}