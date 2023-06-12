#include <string.h>

#define NAMESIZE 30
#define PHONESIZE 10

void CopyName(char** PhoneDirectory, char Name[], int index, const int SIZE) {
	int j = 0;
	for (; PhoneDirectory[index][j] != ' ';  j++)
		Name[j] = PhoneDirectory[index][j];
	Name[j] = '\0';
}

void SortByNames(char** PhoneDirectory, const int SIZE) {
	char Name1[NAMESIZE], Name2[NAMESIZE];
	char Contact1[NAMESIZE + PHONESIZE + 4], Contact2[NAMESIZE + PHONESIZE + 4];

	for (int n = 0; n < SIZE; n++) {
		for (int i = SIZE - 1; i > 0; i--) {
			CopyName(PhoneDirectory, Name1, i, SIZE);
			CopyName(PhoneDirectory, Name2, i-1, SIZE);

			if (strcmp(Name1, Name2) == -1) {
				strcpy_s(Contact1, NAMESIZE + PHONESIZE + 4, PhoneDirectory[i]);
				strcpy_s(Contact2, NAMESIZE + PHONESIZE + 4, PhoneDirectory[i - 1]);

				strcpy_s(PhoneDirectory[i], NAMESIZE + PHONESIZE + 4, Contact2);
				strcpy_s(PhoneDirectory[i - 1], NAMESIZE + PHONESIZE + 4, Contact1);
			}
		}
	}
}

void CopyPhoneNumber(char** PhoneDirectory, char PhoneNumber[], int index, const int SIZE) {
	int j = 0;
	while (PhoneDirectory[index][j] != '-')
		j++;
	j += 2;

	int i = 0;
	for (; j < strlen(PhoneDirectory[index]); j++, i++)
		PhoneNumber[i] = PhoneDirectory[index][j];
	PhoneNumber[i] = '\0';
}

void SortByPhoneNumbers(char** PhoneDirectory, const int SIZE) {
	char PhoneNumber1[PHONESIZE], PhoneNumber2[PHONESIZE];
	char Contact1[NAMESIZE + PHONESIZE + 4], Contact2[NAMESIZE + PHONESIZE + 4];

	for (int n = 0; n < SIZE; n++) {
		for (int i = SIZE - 1; i > 0; i--) {
			CopyPhoneNumber(PhoneDirectory, PhoneNumber1, i, SIZE);
			CopyPhoneNumber(PhoneDirectory, PhoneNumber2, i - 1, SIZE);

			if (strcmp(PhoneNumber1, PhoneNumber2) == -1) {
				strcpy_s(Contact1, NAMESIZE + PHONESIZE + 4, PhoneDirectory[i]);
				strcpy_s(Contact2, NAMESIZE + PHONESIZE + 4, PhoneDirectory[i - 1]);

				strcpy_s(PhoneDirectory[i], NAMESIZE + PHONESIZE + 4, Contact2);
				strcpy_s(PhoneDirectory[i - 1], NAMESIZE + PHONESIZE + 4, Contact1);
			}
		}
	}
}