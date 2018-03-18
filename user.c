#include <string.h>
#include "user.h"


int createUser()
{

    displayCreateUserMenu();

    char username[32];

	printf("Enter unique Username (%d Maximum Length)\n\n", MAXIMUM_USERNAME_LENGTH);

  	scanf("%s", username);

	if (strlen(username) > MAXIMUM_USERNAME_LENGTH) {
	
		puts("Username is too long, try again.");
		scanf("%s", username);
	}


	printf("You entered %s\n\n", username);


	return 0;
   
	

}
