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

Patient searchPatient(int);

void editPatient();

#endif /* PATIENT_H_ */