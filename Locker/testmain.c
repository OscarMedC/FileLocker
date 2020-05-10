#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Functions.h"

int main() {

	struct User *fileLocker = NULL;
	int amountOfUsers = 0;

	fileLocker = addUser(fileLocker, &amountOfUsers);

	fileLocker[0].nrOfFiles = 6;

	printf("%d", fileLocker[0].nrOfFiles);

	for (int i = 0; i < amountOfUsers; i++) {
		free(fileLocker[i].cryptKey);
	}
	free(fileLocker);

	char buffer[5][100];

	int SENTVAL = 0;
	int arrayLength = 0;

	for (int i = 0; i < 5 && SENTVAL == 0; i++) {
		fgets(buffer[i], 100, stdin);
		strtok(buffer[i], "\n");

		if (buffer[i][0] == '-' && buffer[i][1] == '1') {
			SENTVAL = 1;
			arrayLength = i;
		}
	}

	for (int i = 0; i < 5; i++) {
		for (int j = 0; i < arrayLength; i++) {
			printf("%s\n", buffer[i]);
		}
	}


	
	return 0;
}