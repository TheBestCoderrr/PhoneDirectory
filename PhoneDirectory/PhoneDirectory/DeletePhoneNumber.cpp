#include <string.h>

#define NAMESIZE 30
#define PHONESIZE 11

unsigned short int FindPhoneNumberIndex(char** PhoneDirectory, char PhoneNumber[], const int SIZE){
	unsigned short int CountCorrectNumbers = 0, index = 0;

	for (int i = 0; i < SIZE; i++) {
		while (PhoneDirectory[i][index] != '-')
			index++;
		index += 2;

		for (int j = 0; j < strlen(PhoneNumber); j++) {
			if (PhoneDirectory[i][index++] == PhoneNumber[j])
				CountCorrectNumbers++;
		}
		if (CountCorrectNumbers == strlen(PhoneNumber))
			return i;


		index = 0;
	}
}

char** DeletePhoneNumber(char** PhoneDirectory, char PhoneNumber[], int* SIZE) {

	unsigned short int UserIndex = FindPhoneNumberIndex(PhoneDirectory, PhoneNumber, *SIZE);

	for (int i = UserIndex; i < *SIZE - 1; i++) {
		for (int j = 0; j < strlen(PhoneDirectory[i]); j++) {
			PhoneDirectory[i][j] = PhoneDirectory[i + 1][j];
		}
	}

	char** NewPhoneDirectory = new char* [*SIZE];

	for (int i = 0; i < *SIZE; i++)
		NewPhoneDirectory[i] = new char[NAMESIZE + PHONESIZE + 4];

	for (int i = 0; i < *SIZE - 1; i++) {
		for (int j = 0; j < strlen(PhoneDirectory[i]) + 1; j++)
			NewPhoneDirectory[i][j] = PhoneDirectory[i][j];
	}
	delete[] PhoneDirectory;

	*SIZE -= 1;

	return NewPhoneDirectory;
}