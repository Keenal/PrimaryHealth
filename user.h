#ifndef USER_H_
#define USER_H_

#include <stdio.h>
#include "menus.h"

#define MINIMUM_PASSWORD_LENGTH 8
#define MAXIMUM_PASSWORD_LENGTH 32
#define MAXIMUM_USERNAME_LENGTH 32

/**
* Create a new user based on a unique username and a strong password
* @return the error code of whether a user was successfully created or not. 0 for success and -1 for error.
*/
int createUser();

#endif /*USER_H_*/
