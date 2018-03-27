#ifndef LOGIN_H_
#define LOGIN_H_

#include <stdio.h>
#include "menus.h"


/**
 * * Create a new user based on a unique username and a strong password
 * * @return the error code of whether a user was successfully created or not. 0 for success and -1 for error.
 * */
int loginUser();

#endif /*LOGIN_H_*/
