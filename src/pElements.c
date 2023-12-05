#include "../include/cub3D.h"

bool isWhitespace(char c) {
	if (c == ' ' || c == '\f' || c == '\n' || c == '\r' || c == '\v') {
		return true;
	}
	return false;
}

/*
all prefixes are a length of 1 or 2
*/
int getPrefixLength(char *s) {
	int i = 0;
	while(s[i]) {
		if (i >= 4) {
			return -1;
		}
		if (isWhitespace(s[i]) == true) {
			break;
		}
		i++;
	}
	if (i != 2 && i != 3) {
		return -1;
	}
	return i-1;
}

int setElementValues(t_parser *p) {
	
	return 0;
}
