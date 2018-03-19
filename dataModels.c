#include "dataModels.h"
#include "menus.h"

struct varString {
    char chars [MAX_STRING_SIZE];
    int length;
};

struct loginCredentials {
    struct varString userName;
    struct varString hashedPassword;
};

struct assignedUserRoles {
    // put roles here
    // ex:
    // bool isPatient;
    // bool isDoctor;
    // etc.
};

struct userData {
    struct loginCredentials loginCred;
    struct assignedUserRoles roles;

};

struct patientData {
    struct varString firstName;
    struct varString lastName;
    struct varString middleName;
    int ssNumberFirstGrouping;  // valid range is 0 - 999
    int ssNumberSecondGrouping; // valid range is 0 - 99
    int ssNumberThirdGrouping; // valid range is 0 - 9999


};