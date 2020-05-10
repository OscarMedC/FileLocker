#include <stdio.h>

int main() {

	char crypted[6] = "\0";
	char key[] = "KEY";
	char klartext[] = "DCODE";
	char decrypted[6] = "\0";
	int j = 0;

	for (int i = 0; i < 5; i++) {

		if (j >= strlen(key)) {
			j = 0;
		}

		crypted[i] = ((klartext[i] - 32) + (key[j++] - 32)) % 95 + 32;
	}

	printf("%s", crypted);
	int k = 0;

	for (int i = 0; i < 5; i++) {

		if (k >= strlen(key)) {
			k = 0;
		}

		decrypted[i] = ((crypted[i] + 95) - (key[k++])) % 95 + 32;
	}

	printf("%s", decrypted);

	return 0;
}