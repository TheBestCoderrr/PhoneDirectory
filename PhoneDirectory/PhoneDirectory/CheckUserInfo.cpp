#include <string.h>

bool CheckRepeatName(char** PhoneDirectory, char name[], const int SIZE) {
	unsigned short int CountCorrectLetters = 0;

	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < strlen(name); j++) {
			if (PhoneDirectory[i][j] == name[j])
				CountCorrectLetters++;
		}
		if (CountCorrectLetters == strlen(name))
			return true;
	}
	return false;
}

bool CheckRepeatNumber(char** PhoneDirectory, char PhoneNumber[], const int SIZE) { 
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
			return true;
		index = 0;
	}
	return false;
}