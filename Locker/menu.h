#ifndef MENU_H
#define MENU_H
#include "Functions.h"

void menu(int superUser) {
	printf("1. Mata in text.\n");
	printf("2. Spara inmatad text p� en ny fil.\n");
	printf("3. L�gg till inmatad text i en redan befintlig fil.\n");
	printf("4. L�sa fr�n en fil och presentera inneh�llet.\n");
	printf("5. Byt l�senord.\n");
	if (superUser) {
		printf("6. L�gg till anv�ndare.\n");
	}
	printf("0. Logga ut och avsluta.\n");
}


#endif // !MENU_H
