#include "Functions.h"
#include <crtdbg.h>

int main() {
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	struct User *fileLocker = NULL;
	int nrOf = 0;
	int superUser = 0;
	int bufferIndex = 0;
	char **buffer = NULL;
	int activeUserIndex = -1;
	int choice = -1;

	//Lägger till två användare
	fileLocker = addUser(fileLocker, &nrOf);
	fileLocker = addUser(fileLocker, &nrOf);

	//Använd användarnamnet "Oscar" 
	//och lösenordet "kalle" för att logga
	//in som superuser

	do {
		printf("\nVar vänlig och logga in\n");
		activeUserIndex = findUser(fileLocker, nrOf);
		if (activeUserIndex == -1) {
			printf("Ogiltig inlogg!");
		}
	} while (activeUserIndex == -1);

	superUser = isSuper(fileLocker, activeUserIndex);

		while (choice != 0) {

			printf("\n");
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
				printToFile(fileLocker, activeUserIndex, buffer, bufferIndex);
				break;
			case 3:
				addToFile(fileLocker, activeUserIndex, buffer, bufferIndex);
				break;
			case 4:
				decryptText(fileLocker, activeUserIndex);
				break;
			case 5:
				changePassword(fileLocker, activeUserIndex);
				break;
			case 6:
				if (superUser == 1) {
					fileLocker = addUser(fileLocker, &nrOf);
				}
				else
					printf("Snälla slå in ett giltigt val!\n");
				break;
			case 0:
				choice = 0;
				freeMemory(buffer, fileLocker, nrOf, bufferIndex);
				break;
			default:
				printf("Snälla slå in ett giltigt val!\n");
				choice = -1;
				break;
			}
		}

	return 0;
}
