#include "../include/cub3D.h"

void freeArr(char **stringArr) {
	int i = 0;
	while(stringArr[i] != NULL) {
		free(stringArr[i]);
		i++;
	}
	free(stringArr);
}

void printArr(char **stringArr) {
	int i = 0;
	while(stringArr[i] != NULL) {
		printf("%s\n", stringArr[i]);
		i++;
	}
}

int parserError(char *errorText) {
	printf("Error\n");
	printf("%s", errorText);
	return 1;
}

char **callocStringArr(int amount) {
	char **stringArr;
	int i;

	stringArr = malloc((sizeof(char *) + 1) * amount);
	if (stringArr == NULL) {
		return NULL;
	}	
	i = 0;
	while(i <= amount) {
		stringArr[i] = NULL;
		i++;
	}
	return stringArr;
}

int getLengthArr(char **stringArr) {
	int i = 0;
	while(stringArr[i] != NULL) {		
		i++;
	}
	return i;
}
