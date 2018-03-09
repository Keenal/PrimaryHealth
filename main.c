#include <stdio.h>

void start();
void displayMainMenu();

int main(int argc, char** argv)
{

    puts("Welcome to the PrimaryHealth application!");
    start();

}

void start()
{

    int ans = 0;
    puts("How might I help you today?");
    displayMainMenu();

}

void displayMainMenu()
{

        puts("1. Create User");
        puts("2. Login");

}
