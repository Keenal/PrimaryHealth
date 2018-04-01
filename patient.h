#ifndef PATIENT_H_
#define PATIENT_H_

#define MAX_NAME_SIZE 32

typedef struct patient* Patient;

Patient createPatient(const char* name,
    int id,
    int dob,
    char gender,
    double height,
    double weight
);

void editPatient();

void printPatient(Patient patient);

#endif /* PATIENT_H_ */