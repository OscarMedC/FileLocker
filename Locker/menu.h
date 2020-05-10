#ifndef MENU_H
#define MENU_H
#include "Functions.h"

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


#endif // !MENU_H
