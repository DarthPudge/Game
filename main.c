#include <stdio.h>
#include <stdlib.h>
#include <time.h>




int main()
{
	int array[5], buffer[5];
	char ch = ' ';
	int size = 0, buff = 0, digits = 0, no_equal = 0;
	int bulls = 0, cows = 0;
	int attempts = 0;

	do {
		printf("Enter digit number (from 2 to 5): ");
		scanf_s("%d", &size);
		if (size < 2 || size > 5)
			printf("You made a mistake, please enter a number from 2 to 5\n\n");
	} while (size < 2 || size > 5);

	srand((unsigned int)time(NULL));
	array[0] = 1 + rand() % 9;
	digits++;
	while (digits < size) {
		buff = rand() % 10;
		no_equal = digits;
		for (int i = 0; i < digits; i++)
			if (buff != array[i]) no_equal--;
		if (no_equal == 0) {
			array[digits] = buff;
			digits++;
		}
	}
	digits = no_equal = 0;
	printf("Enter %d Digits or <q> for Exit: \n", size);
	while (ch != 'q' && ch != 'Q') {
		ch = _getch();
		if (isdigit(ch)) {
			buff = (int)(ch - 48);
			if (digits == 0 && buff == 0)
				continue;
			buffer[digits] = buff;
			no_equal = digits;
			for (int i = 0; i < digits; i++)
				if (buff != buffer[i]) no_equal--;
			if (no_equal == 0) {
				printf("%d", buff);
				for (int i = 0; i < size; i++)
					if (array[i] == buff)
						if (i == digits)
							bulls++;
						else
							cows++;
				digits++;
				if (digits == size) {
					attempts++;
					printf("\tAttempt %d: ", attempts);
					printf("\tBulls: %d, Cows: %d\n", bulls, cows);
					if (bulls == size) {
						printf("Congratulations! You guessed the number with %d attempt(s)!", attempts);
						break;
					}
					digits = bulls = cows = 0;
				}
			}
		}
	}
	return 0;
}