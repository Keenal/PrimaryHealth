#ifndef USER_H_
#define USER_H_

#define MAX_USERNAME 32
#define MAX_PASSWORD 32

typedef struct user* User;

User makeUser();

void printUser(User user);

#endif /* USER_H_ */