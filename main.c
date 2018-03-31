#include <stdio.h>
#include "user.h"

void start();

int main(int argc, char** argv)
{

    puts("Welcome to the PrimaryHealth application!");
    start();

}

void start()
{

    puts("Starting application...");
    User newUser = makeUser();

}