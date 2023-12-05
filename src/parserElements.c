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

// int fillPrefixArray(char ) {

// }

/*
array of prefixes
*/
int setElements(t_parser *p) {
	// int i = 0;
	// while (p->readout[i] != NULL) {
	// 	int prefixLen = getPrefixLength(p->readout[i]);
	// 	if (prefixLen == -1) {
	// 		break;
	// 	}
		
	// 	char *prefix;
	// 	prefix = ft_substr(file, 0, i);
	// 	if (prefix == NULL) {
	// 		free(prefix);
	// 		return 1;
	// 	}
	// 	free(prefix);
	// 	i++;
	// }
	return 0;
}

	// printf("|%s|\n", p->readout[i]);
	// printf("{%s}\n", prefix);
