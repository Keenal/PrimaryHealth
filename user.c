#include <string.h>
#include "user.h"


int createUser()
{

    displayCreateUserMenu();
    printf("Unique Username (%d Maximum Length):\n", MAXIMUM_USERNAME_LENGTH);
    char username[MAXIMUM_USERNAME_LENGTH + 2];
    fgets(username, sizeof(username), stdin);
    if (strlen(username) > MAXIMUM_USERNAME_LENGTH)
    {

        puts("Username too long.");

    }
    printf("Username: %s\n", username);

    return 0;

}
