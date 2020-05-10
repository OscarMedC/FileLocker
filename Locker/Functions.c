#include "Functions.h"

struct User* addUser(struct User* userLocker, int *nrOf) {

	struct User* tempLocker = NULL;
	tempLocker = (struct User*)malloc(sizeof(struct User) * (*nrOf + 1));

	if (tempLocker == NULL) {
		printf("Allocation of memory not successfull!\n\n");
	}

	if (tempLocker != NULL) {

		printf("Enter your username: ");
		fgets(tempLocker[*nrOf].userName, 20, stdin);
		strtok(tempLocker[*nrOf].userName, "\n");

		printf("Enter a password: ");
		fgets(tempLocker[*nrOf].password, 20, stdin);
		strtok(tempLocker[*nrOf].password, "\n");

		tempLocker[*nrOf].nrOfFiles = 0;

		tempLocker[*nrOf].cryptKey = NULL;
		tempLocker[*nrOf].cryptKey = cryptKey();

		for (int i = 0; i < *nrOf; i++) {
			tempLocker[i] = userLocker[i];
		}

		free(userLocker);
		userLocker = tempLocker;
		tempLocker = NULL;
		++*nrOf;
	}
	return userLocker;
}

char** addText(char **buffer, int *bufferSize) {

	int SENTVAL = 0;
	buffer = (char**)calloc(50, sizeof(char*)); //tidigare 100

	for (int i = 0; i < 50; i++)
	{
		buffer[i] = (char*)malloc(sizeof(char) * 300); //tidigare 500
	}

	for (int i = 0; i < 100 && SENTVAL == 0; i++) {
		fgets(buffer[i], 300, stdin);
		buffer[i][strlen(buffer[i])] = '\0';
		strtok(buffer[i], "\n");

		if (buffer[i][0] == '-' && buffer[i][1] == '1') {
			SENTVAL = 1;
			*bufferSize = i;
		}
	}
	return buffer;
}

void printToFile(struct User* userLocker, int activeUser, char **buffer, int bufferSize) {

	FILE *fp;

	printf("Skriv in namnet på filen du vill skapa (xxxxx.txt): ");
	fgets(userLocker[activeUser].pathToFiles[userLocker[activeUser].nrOfFiles], 20, stdin);
	strtok(userLocker[activeUser].pathToFiles[userLocker[activeUser].nrOfFiles], "\n");
	fp = fopen(userLocker[activeUser].pathToFiles[userLocker[activeUser].nrOfFiles], "w+");

	cryptText(buffer, userLocker, activeUser, bufferSize);

	for (int i = 0; i < bufferSize; i++) {
		fputs(buffer[i], fp);
		fputs("\n", fp);
	}

	++userLocker[activeUser].nrOfFiles;
	fclose(fp);
}

void addToFile(struct User* userLocker, int activeUser, char **buffer, int bufferSize) {

	FILE *fp;
	char fileName[FILENAME_SIZE];

	for (int i = 0; i < userLocker[activeUser].nrOfFiles; i++) {
		printf("%s\n", userLocker[activeUser].pathToFiles[i]);
	}

	printf("Vilken fil vill du öppna: ");
	fgets(fileName, FILENAME_SIZE, stdin);
	strtok(fileName, "\n");

	fp = fopen(fileName, "a");
	cryptText(buffer, userLocker, activeUser, bufferSize);

	for (int i = 0; i < bufferSize; i++) {
		//fputs("\n", fp);
		fputs(buffer[i], fp);
		fputs("\n", fp);
	}

	fclose(fp);

}

void changePassword(struct User* userLocker, int activeUser) {
	printf("Enter your new password: ");
	fgets(userLocker[activeUser].password, 20, stdin);
	strtok(userLocker[activeUser].password, "\n");
}

void cryptText(char **textBuffer, struct User* userLocker, int activeUser, int bufferSize) {

	int j = 0;
	int k = 0;

	for (int i = 0; i < bufferSize; i++) {

		for (int k = 0; k < strlen(textBuffer[i]); k++) {

			if (j >= strlen(userLocker[activeUser].cryptKey)) {
				j = 0;
			}

			textBuffer[i][k] = ((textBuffer[i][k] - 32) + (userLocker[activeUser].cryptKey[j++] - 32)) % 95 + 32;
		}
		j = 0;
	}
}

void decryptText(struct User* userLocker, int activeUser) {

	FILE *fp;
	char fileName[FILENAME_SIZE];
	char aLine[500];
	int j = 0;

	for (int i = 0; i < userLocker[activeUser].nrOfFiles; i++) {
		printf("%s\n", userLocker[activeUser].pathToFiles[i]);
	}

	printf("Vilken fil vill du öppna: ");
	fgets(fileName, FILENAME_SIZE, stdin);
	strtok(fileName, "\n");

	fp = fopen(fileName, "r+");

	if (fp != NULL) {

		while (fgets(aLine, sizeof aLine, fp) != NULL) {
			strtok(aLine, "\n");

				for (int k = 0; k < strlen(aLine); k++) {

					if (j >= strlen(userLocker[activeUser].cryptKey)) {
						j = 0;
					}

					aLine[k] = ((aLine[k] + 95) - (userLocker[activeUser].cryptKey[j++])) % 95 + 32;
				}
				j = 0;
				printf("%s\n", aLine);
			}
			fclose(fp);
		}
	else
		printf("Kunde inte öppna filen");
}

char* cryptKey() {

	srand(time(NULL));
	char *cryptKey = NULL;

	int keyLength = rand() % 5 + 3;

	cryptKey = (char *)malloc(sizeof(char *) * (keyLength + 1));

	for (int i = 0; i < keyLength; i++) {
		cryptKey[i] = rand() % 95 + 32;
	}
	cryptKey[keyLength + 1] = '\0';
	return cryptKey;
}

void freeBuffer(char **buffer) {

	for (int i = 0; i < 50; i++) {
		free(buffer[i]);
	}
	free(buffer);
}

void freeMemory(char **buffer, struct User* fileLocker, int nrOf, int bufferIndex) {

	for (int i = 0; i < nrOf; i++) {
		free(fileLocker[i].cryptKey);
	}

	free(fileLocker);

	if (bufferIndex != 0) {
		for (int i = 0; i < 50; i++) {
			free(buffer[i]);
		}
		free(buffer);
	}
}

int findUser(struct User* userLocker, int nrOf) {

	int found = -1;
	char activeUser[20];
	char activePassword[20];

	printf("Enter Your Username: ");
	fgets(activeUser, sizeof(activeUser), stdin);
	strtok(activeUser, "\n");

	printf("Enter Your Password: ");
	fgets(activePassword, sizeof(activePassword), stdin);
	strtok(activePassword, "\n");

	for (int i = 0; i < nrOf && found == -1; i++) {

		if (strcmp(userLocker[i].userName, activeUser) == 0 && strcmp(userLocker[i].password, activePassword) == 0) {
			found = i;
		}
	}
	return found;
}

int isSuper(struct User* userLocker, int activeUser){

	int superUser = 0;
	char superUsername[] = "Oscar";
	char superPassword[] = "kalle";

	if (strcmp(userLocker[activeUser].userName, superUsername) == 0 && strcmp(userLocker[activeUser].password, superPassword) == 0) {
		
		superUser = 1;
	}

	return superUser;
}

void menu(int superUser) {
	printf("1. Mata in text.\n");
	printf("2. Spara inmatad text på en ny fil.\n");
	printf("3. Lägg till inmatad text i en redan befintlig fil.\n");
	printf("4. Läsa från en fil och presentera innehållet.\n");
	printf("5. Byt lösenord.\n");
	if (superUser) {
		printf("6. Lägg till användare.\n");
	}
	printf("0. Logga ut och avsluta.\n");
}