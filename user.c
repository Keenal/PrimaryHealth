#include <string.h>
#include "user.h"


int createUser()
{

    displayCreateUserMenu();

    char username[32];
    char password[32];

	// user is asked to enter username
	printf("Enter unique Username: (%d Maximum Length)\n", MAXIMUM_USERNAME_LENGTH);
	scanf("%s", username);
	printf("\n");

	// user is asked to enter username again if it is longer than the max username length
	while(strlen(username) > MAXIMUM_USERNAME_LENGTH) {
		puts("Username is too long, try again.");
		scanf("%s", username);
	}

	// user is asked to enter password
	printf("Enter password (%d Minimum Length, %d Maximum Length)\n", MINIMUM_PASSWORD_LENGTH, MAXIMUM_PASSWORD_LENGTH);
	scanf("%s", password);
	printf("\n");

	// user is asked to enter password again if it it longer than the max password length
	while(strlen(password) > MAXIMUM_PASSWORD_LENGTH){
		puts("Password is too long, try again");
		scanf("%s", password);
		}

	// user is asked to enter password again if it is shorter than the min password length
	while(strlen(password) < MINIMUM_PASSWORD_LENGTH){
		puts("Password is too short, try again");
		scanf("%s", password);
		}

	// lets user know which username they have typed
	printf("\nYour username is:  %s\n\n", username);
	
	// lets user know which password they have typed
	printf("Your password is:  %s\n\n", password);

	printf("You have successfully been registered");
	return 0;
   
	

}
