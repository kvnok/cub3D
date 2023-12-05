#include "../include/cub3D.h"

// count elements
int loopThroughElements(char *str, int *elementCount) {
	int i = 1;
	if (ft_isalpha(str[0]) == 1) {
		(*elementCount)++;
	}
	while(str[i]) {
		if (str[i-1] == '\n' && str[i] != '\n' && ft_isalpha(str[i]) == false) {
			break;
		}
		if (str[i-1] == '\n' && ft_isalpha(str[i]) == true) {
			(*elementCount)++;
		}
		if (*elementCount == 6) {
			while(str[i] && str[i] != '\n') {
				i++;
			}
			break;
		}
		i++;
	}
	return i;
}

/*
looping through the first part
incrementing 
*/
int checkElementCountandNewlines(char *s) {
	int elementCount = 0;
	int i = loopThroughElements(s, &elementCount);
	// printf("elementCount: %d\n", elementCount);
	if (elementCount != 6) {
		return parserError("Does not have 6 elements\n");
	}
	// printf("|%s|\n", s);
	while(s[i] && s[i] == '\n')
		i++;
	while(s[i]) {
		if (s[i - 1] == '\n' && s[i] == '\n') {
			return parserError("map contains extra newline\n");
		}
		if (s[i] == '\n' && !(s[i-1] == '1' || s[i-1] == '0')) {
			return parserError("invalid map line\n");
		}
		i++;
	}
	return 0;
}

bool isFileNameCorrect(char *fileName) {
	int len = int_strlen(fileName);
	if (len <= 4 || fileName[len-5] == '/') {
		return false;
	}
	if (fileName[len-4] == '.' && fileName[len-3] == 'c' && fileName[len-2] == 'u' && fileName[len-1] == 'b') {
		return true;
	}
	return false;
}
