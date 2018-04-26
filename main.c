#include <stdio.h>
#include <stdlib.h>
#include "menus.h"
#include "patient.h"
#include "database.h"
#include "admin.h"
#include "doc.h"
#include "nurse.h"
#include "helpers.h"

void start();

int handleInput(int, Database);

int main(int argc, const char **argv) {
    if (puts("\nWelcome to the PrimaryHealth application!\n")){}
    start();
}

void start() {
    Database mockdatabase;
    mockdatabase = createDatabase();
    long ans;
    while (1) {
        displayMainMenu();
        ans = getNumericResponse();
        if (ans > 0) {
            if (handleInput(ans, mockdatabase) == 1) {
                freeDatabase(mockdatabase);
                mockdatabase = NULL;
                exit(0);
            }
        } else {
            if (puts("You did not input a number. You must put a number representing one of the options. Ex: For option 1 you would type \"1\"")){}
        }
    }


}

int handleInput(int option, Database mockdatabase) {
    if (option == 1) {
        if (puts("You are logged in as a Doctor.")){}
        docMain(mockdatabase);
    } else if (option == 2) {
        if (puts("You are logged in as a Nurse.")){}
        nurseMain(mockdatabase);
    } else if (option == 3) {
        if (puts("You are logged in as an Admin.")){}
        adminMain(mockdatabase);
    } else if (option == 4) {
        if (puts("Exiting the program")){}
        return 1;
    } else {
        if (puts("Invalid option selected...")){}
    }
    return 0;
}
