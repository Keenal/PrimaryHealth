#include <string.h>
#include "login.h"

int loginUser(){

	displayCreateUserMenu();

	printf("You are logged in as: [write the username here from user.c class]\n\n");

	int ans = 0;

	puts("What would you like to do?\n");
	puts("1. Create a patient");
	puts("2. Edit a patient");
	puts("3. Search a patient");
	puts("4. Logout");

	int result = scanf("%d", &ans);

	if(result < 1 || result > 4){
		puts("You did not input a number. You must put a number representing one of the options. Ex: For option 1 you would type \"1\"");
	}

	if(result == 1){
		puts("You selected 1: Create a patient");
		createPatient();
	}

	if(result == 2){
		puts("You selected 2: Edit a patient");
		editPatient();
	}

	if(result == 3){
		puts("You selected 3: Search a patient");
		searchPatient();
	}

	if(result == 4){
		puts("You selected 4: Logging out");
		logout();
	}


}

void createPatient(){
	puts("testing createPatient method");
}

void editPatient(){
	puts("testing editPatient method");
}

void searchPatient(){
	puts("testing searchPatient method");
}

void logout(){
	puts("testing logout method");
}
