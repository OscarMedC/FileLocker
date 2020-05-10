#include "Functions.h"

//for (int i = 0; i < 14; i++) {
//
//	if (j >= strlen(password)) {
//		j = 0;
//	}
//
//	crypted[i] = ((klartext[i] - 32) + (password[j++] - 32)) % 95 + 32;
//}

void addUser(struct User* userLocker, int *nrOf) {

	struct User* tempLocker = NULL;
	tempLocker = (struct User*)malloc(sizeof(struct User) + (*nrOf + 1));

	if (tempLocker == NULL) {
		printf("Allocation of memory not successfull!\n\n");
	}

	if (tempLocker != NULL) {
		for (int i = 0; i < *nrOf; i++) {
			tempLocker[i] = userLocker[i];
		}

		printf("Enter your username: ");
		fgets(tempLocker[*nrOf].userName, 20, stdin);
		strtok(tempLocker[*nrOf].userName, "\n");

		printf("Enter a password: ");
		fgets(tempLocker[*nrOf].password, 20, stdin);
		strtok(tempLocker[*nrOf].password, "\n");

		free(userLocker);
		userLocker = tempLocker;
		tempLocker = NULL;
		*nrOf++;
	}
}