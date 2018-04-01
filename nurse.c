#include <stdio.h>
#include <string.h>
#include "nurse.h"

void nurseMain(Database database){
	while(1){
	puts("1. Search a patient");

	int nurseOption;
	int result = scanf("%d", &nurseOption);

	if(result > 0){

	if(nurseOption == 1){

	findingPatient(database);
	}
	
	}
	else {
	puts("You did not input a correct number.");
	}	

	}		

}

void findingPatientNurse(Database database){
        puts("Please input the id of the patient you would like to search");

        int id;
        int result = scanf("%d", &id);
        if(result <= 0){
        puts("This is not a valid patient id.");
        return;
}

        Patient patientToFind = findPatient(database, id);
        printPatients(database);
        if(patientToFind == NULL){
        puts("This patient ID does not match our database");
        return;
}


}
