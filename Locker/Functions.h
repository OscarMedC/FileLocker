#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define USER_NAME_SIZE 20
#define PASSWORD_SIZE 20
#define NR_OF_FILES 10
#define FILENAME_SIZE 20

struct User {

	char userName[USER_NAME_SIZE];
	char password[PASSWORD_SIZE];
	char *cryptKey;
	char pathToFiles[NR_OF_FILES][FILENAME_SIZE];
	int nrOfFiles;
};

void menu(int superUser);
struct User* addUser(struct User* userLocker, int *nrOf);
int findUser(struct User* userLocker, int nrOf);
int isSuper(struct User* userLocker, int activeUser);
char* cryptKey();
char** addText(char **buffer, int *bufferSize);
void printToFile(struct User* userLocker, int activeUser, char **buffer, int bufferSize);
void addToFile(struct User* userLocker, int activeUser, char **buffer, int bufferSize);
void changePassword(struct User* userLocker, int activeUser);
void cryptText(char **textBuffer, struct User* userLocker, int activeUser, int bufferSize);
void decryptText(struct User* userLocker, int activeUser);
void freeBuffer(char **buffer);
void freeMemory(char **buffer, struct User* fileLocker, int nrOf, int bufferIndex);

#endif
