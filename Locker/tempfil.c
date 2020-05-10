struct User *fileLocker = NULL;
int nrOf = 0;
int superUser = 0;
int bufferIndex = 0;
char **buffer = NULL;
char activeUser[20];
char activePassword[20];
char superUsername[] = "Oscar";
char superPassword[] = "kalle";
int activeUserIndex = -1;

int choice = -1;

fileLocker = addUser(fileLocker, &nrOf);
fileLocker = addUser(fileLocker, &nrOf);

do {

	printf("Enter Your Username: ");
	fgets(activeUser, sizeof(activeUser), stdin);
	strtok(activeUser, "\n");

	printf("Enter Your Password: ");
	fgets(activePassword, sizeof(activePassword), stdin);
	strtok(activePassword, "\n");

	if (strcmp(superUsername, activeUser) == 0) {
		if (strcmp(superPassword, activePassword) == 0) {
			printf("Hello SuperUser\n");
			fileLocker = addUser(fileLocker, &nrOf);
			superUser = 1;
		}
	}
	else
		activeUserIndex = findUser(fileLocker, &nrOf, activeUser, activePassword);

} while (activeUserIndex == -1 && superUser != 1);

printf("%d\n\n", activeUserIndex);

if (activeUserIndex != -1 || superUser == 1) {

	while (choice != 0) {

		menu(superUser);
		scanf("%d", &choice);
		getchar();

		switch (choice)
		{

		case 1:
			if (bufferIndex != 0) {

				freeBuffer(buffer);
			}
			buffer = addText(buffer, &bufferIndex);
			break;
		case 2:
			printToFile(fileLocker, 0, buffer, bufferIndex);
			break;
		case 3:
			addToFile(fileLocker, 0, buffer, bufferIndex);
			break;
		case 4:
			decryptText(fileLocker, 0);
			break;
		case 5:
			changePassword(fileLocker, 0);
			break;
		case 6:
			fileLocker = addUser(fileLocker, &nrOf);
			break;
		case 0:
			choice = 0;
			freeMemory(buffer, fileLocker, nrOf);
			break;
		default:
			choice = -1;
			break;
		}
	}
}
return 0;
}

//
//if (fp != NULL) {
//	while (fgets(aLine, sizeof aLine, fp) != NULL) {
//		for (int i = 0; i < bufferSize; i++) {
//			for (int k = 0; k < strlen(textBuffer[i]); k++) {
//				if (j >= strlen(userLocker[activeUser].cryptKey)) {
//					j = 0;
//				}
//				aLine[k] = ((aLine[k] + 95) - (userLocker[activeUser].cryptKey[j++])) % 95 + 32;
//			}
//			printf("%s", aLine);
//		}
//		fclose(fp);
//	}
//}
//else
//printf("Kunde inte öppna filen");

///////////////////////////////////////////////
////Kolla om jag kan bryta ut detta till en egen funktion
//tempLocker[*nrOf].cryptKey = NULL;
///*srand(time(NULL));
//
//int keyLength = rand() % 5 + 3;
//
//tempLocker[*nrOf].cryptKey = (char *)malloc(sizeof(char *) * (keyLength + 1));
//
//for (int i = 0; i < keyLength; i++) {
//tempLocker[*nrOf].cryptKey[i] = rand() % 95 + 32;
//}
//tempLocker[*nrOf].cryptKey[keyLength + 1] = '\0';*/
//tempLocker[*nrOf].cryptKey = cryptKey();
////////////////////////////////////////////////////

//int SENTVAL = 0;
//buffer = (char**)calloc(2, sizeof(char*)); //tidigare 100
//
//for (int i = 0; i < 2; i++)
//{
//	buffer[i] = (char*)calloc(150, sizeof(char)); //tidigare 500
//}

//void readFromFile(struct User* userLocker, int activeUser) {
//
//	FILE *fp;
//	char fileName[FILENAME_SIZE];
//	char aLine[500];
//
//	for (int i = 0; i < userLocker[activeUser].nrOfFiles; i++) {
//		printf("%s\n", userLocker[activeUser].pathToFiles[i]);
//	}
//	printf("Vilken fil vill du öppna: ");
//	fgets(fileName, FILENAME_SIZE, stdin);
//	strtok(fileName, "\n");
//
//	fp = fopen(fileName, "r+");
//
//	if (fp != NULL) {
//
//		while (fgets(aLine, sizeof aLine, fp) != NULL) {
//
//			printf("%s", aLine);
//		}
//		fclose(fp);
//	}
//	else
//		printf("Kunde inte öppna filen");
//
//}

//void decryptText(char **textBuffer, struct User* userLocker, int activeUser, int bufferSize) {
//
//	FILE *fp;
//	char fileName[FILENAME_SIZE];
//	char aLine[500];
//	int j = 0;
//
//	for (int i = 0; i < userLocker[activeUser].nrOfFiles; i++) {
//		printf("%s\n", userLocker[activeUser].pathToFiles[i]);
//	}
//
//	printf("Vilken fil vill du öppna: ");
//	fgets(fileName, FILENAME_SIZE, stdin);
//	strtok(fileName, "\n");
//
//	fp = fopen(fileName, "r+");
//
//	if (fp != NULL) {
//
//		while (fgets(aLine, sizeof aLine, fp) != NULL) {
//			strtok(aLine, "\n");
//
//			for (int k = 0; k < strlen(aLine); k++) {
//
//				if (j >= strlen(userLocker[activeUser].cryptKey)) {
//					j = 0;
//				}
//
//				aLine[k] = ((aLine[k] + 95) - (userLocker[activeUser].cryptKey[j++])) % 95 + 32;
//			}
//
//			printf("%s\n", aLine);
//		}
//		fclose(fp);
//	}
//	else
//		printf("Kunde inte öppna filen");
//}

//int findUser(struct User* userLocker, int *nrOf, char activeUsername[], char activePassword[]) {
//
//	int found = -1;
//	char superUsername[] = "Oscar";
//	char superPassword[] = "kalle";
//
//	for (int i = 0; i < *nrOf; i++) {
//		if (strcmp(userLocker[i].userName, activeUsername) == 0) {
//			if (strcmp(userLocker[i].password, activePassword) == 0) {
//				printf("Hello Ordinary User\n");
//				found = i;
//			}
//		}
//	}
//	return found;
//}


//for (int i = 0; i < 14; i++) {
//
//	if (j >= strlen(password)) {
//		j = 0;
//	}
//
//	crypted[i] = ((klartext[i] - 32) + (password[j++] - 32)) % 95 + 32;
//}

struct User* addUser(struct User* userLocker, int *nrOf);
//int findUser(struct User* userLocker, int *nrOf, char activeUsername[], char activePassword[]);
int findUser(struct User* userLocker, int nrOf);
int isSuper(struct User* userLocker, int activeUser);
char* cryptKey();
char** addText(char **buffer, int *bufferSize);
void printToFile(struct User* userLocker, int activeUser, char **buffer, int bufferSize);
//void readFromFile(struct User* userLocker, int activeUser);
void addToFile(struct User* userLocker, int activeUser, char **buffer, int bufferSize);
void changePassword(struct User* userLocker, int activeUser);
void cryptText(char **textBuffer, struct User* userLocker, int activeUser, int bufferSize);
//void decryptText(char **textBuffer, struct User* userLocker, int activeUser, int bufferSize);
void decryptText(struct User* userLocker, int activeUser);
void freeBuffer(char **buffer);
void freeMemory(char **buffer, struct User* fileLocker, int nrOf, int bufferIndex);