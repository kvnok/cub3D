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

void printDict(t_parser *p) {
	int i = 0;
	while (i < 6) {
		printf("----------------\n");
		printf("key:|%s|\n", p->dict[i].key);
		printf("flag:%d\n", p->dict[i].flag);
		printf("value:|%s|\n", p->dict[i].value);
		printf("----------------\n");
		i++;
	}	
}

int32_t pixel_select(int32_t r, int32_t g, int32_t b, int32_t a) {
	return (r << 24 | g << 16 | b << 8 | a);
}

void print_extracted_rgba(int32_t val, char *s) {
	printf("%s", s);
	printf("|%d|", ((val >> 24) & 0xFF));
	printf("%d|", ((val >> 16) & 0xFF));
	printf("%d|", ((val >> 8) & 0xFF));
	printf("%d|\n", ((val >> 0) & 0xFF));
}
