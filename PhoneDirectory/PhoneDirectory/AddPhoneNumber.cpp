#include <string.h>

#define NAMESIZE 30
#define PHONESIZE 11

char** AddPhoneNumber(char** PhoneDirectory, char name[], char PhoneNumber[], int* SIZE) {
	*SIZE += 1;
	char** NewPhoneDirectory = new char* [*SIZE];

	for (int i = 0; i < *SIZE; i++)
		NewPhoneDirectory[i] = new char[NAMESIZE + PHONESIZE + 4];

	for (int i = 0; i < *SIZE - 1; i++) {
		for (int j = 0; j < strlen(PhoneDirectory[i]) + 1; j++)
			NewPhoneDirectory[i][j] = PhoneDirectory[i][j];
	}
	delete[] PhoneDirectory;

	strcpy_s(NewPhoneDirectory[*SIZE - 1], NAMESIZE, name);
	strcat_s(NewPhoneDirectory[*SIZE - 1], NAMESIZE + 3, " - ");
	strcat_s(NewPhoneDirectory[*SIZE - 1], NAMESIZE + 3 + PHONESIZE, PhoneNumber);
	NewPhoneDirectory[*SIZE - 1][strlen(name) + strlen(PhoneNumber) + 3] = '\0';

	return NewPhoneDirectory;
}